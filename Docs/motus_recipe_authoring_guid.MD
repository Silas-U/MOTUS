# Writing Motus Recipes: An Architecture-Aware Guide

This guide is written against Motus's current event-driven orchestrator
architecture (DAG over typed `Step` objects, JIT motion-merging, async
tool dispatch). It assumes you understand *what* a recipe does
conceptually; the goal here is to help you write one that compiles,
runs, and behaves the way you expect on the first try — by
understanding *why* the system behaves the way it does, not just
copying a template.

---

## 1. The step types, and what each one actually does

A recipe is a flat YAML list of steps under `steps:`. Every step has a
unique `id`, a `type`, and a `depends_on` list. Five step types exist:

| type | Purpose | Key fields |
|---|---|---|
| `move` | Pose-only Cartesian/joint-space motion | `traj_method`, `target_pose`, `blend_radius`, `speed_scale` |
| `tool` | Actuate an end-effector (gripper, vacuum, etc.) | `tool_id`, `command`, `recovery`, `max_retries` |
| `io` | Raw digital/analog I/O | `io_id`, `command` |
| `wait` | Fixed time delay | `duration_sec` |
| `vision` | Vision-system operation | `vision_id`, `operation`, `params` |

**Important architectural fact: `move` steps are pose-only.** There is
no raw-joint-target step type in the recipe schema — this was a
deliberate design decision (an earlier joint-target step type was
removed) because mixing arbitrary joint configs with pose targets
gives no continuity guarantee between legs. If you're tempted to
specify a joint configuration directly to "get around" an IK
ambiguity, don't — solve it with a better seed/posture bias or an
intermediate waypoint pose instead. Manual joint jogging exists as a
separate, deliberately-unreachable-from-recipes tool (`joint_jog_server`)
for exactly this reason: recipes and manual joint control are meant to
stay separate.

---

## 2. `traj_method`: choosing `js` vs `ts`

- **`js` (joint-space, movej-style):** interpolates in joint space.
  Use for long traverses between stations where the path shape in
  Cartesian space doesn't matter — faster, avoids singularities more
  gracefully, and is the natural choice for "get from A to B" moves.
- **`ts` (task-space, movel-style):** interpolates linearly in
  Cartesian space. Use for anything where the *path* matters:
  descending straight down onto a part, inserting along an approach
  axis, retracting straight back out. If your `insert_*`/`retract_*`
  steps use `js` instead of `ts`, you'll get a curved path that may
  collide with the sides of a hole or a part — this is a common
  authoring mistake.

**Rule of thumb:** traverses = `js`, anything touching/approaching a
part = `ts`.

---

## 3. `depends_on`: two very different kinds of dependency

```yaml
depends_on: [previous_step_id]                          # plain — waits for full completion
depends_on:
  - {progress: previous_step_id, threshold: 0.85}        # progress — fires at X% through
```

**Plain dependencies** wait for the full completion of the referenced
step(s). **Progress dependencies** unblock as soon as the referenced
step's motion feedback reports `leg_percent_complete >= threshold` —
this is how you get a grip-close to start *while the arm is still
finishing its descent*, instead of waiting for a full stop first.

This distinction is not cosmetic — it directly controls **motion
merging** (next section). Get this wrong and you'll either get jerky
stop-start motion where you wanted a smooth blend, or unwanted blending
where you needed a full stop.

**Practical guidance:**
- Use progress-deps for tool ops that should overlap the tail end of a
  motion (grip-close during final descent, grip-open during final
  insertion). `threshold: 0.85`–`0.9` is a reasonable starting point —
  tune based on your motion's speed and the tool's actuation time.
- Use plain deps between consecutive `move` steps you want blended
  into one smooth run (see below), and between anything where a full,
  settled stop is required before the next action.

---

## 4. Motion merging — the most important internal behavior to understand

The orchestrator automatically detects maximal chains of consecutive
`move` steps connected by a **single plain (non-progress) dependency**
and dispatches the *entire chain* as one merged multi-leg motion goal.
This is not something you configure — it's inferred purely from your
`depends_on` structure. Understanding this explains a lot of
real-world recipe behavior:

- **Only the true final leg in a merged chain decelerates to zero
  velocity.** Every intermediate leg blends through via its own
  `blend_radius` — the arm does not stop between them.
- **A tool step or a progress-dependency in the chain breaks the
  merge.** e.g. `traverse → descend → [grip_close via progress dep] →
  retract → traverse → descend` naturally produces two separate merged
  runs (separated at the grip event) rather than one continuous blend
  through the gripper action — which is exactly what you want, since
  you can't blend through a physical actuation.
- **If you need a full, settled stop between two `move` steps for
  accuracy** (e.g. before a precision `ts` insertion), don't just set
  `blend_radius: 0.0` on the boundary leg and assume that's sufficient
  — verify in sim/RViz that the behavior you get matches what you
  need. `blend_radius` shapes the corner-rounding path on interior
  legs; it is not the same guarantee as being outside a merged chain
  entirely.

**Practical guidance:** before assuming a recipe's motion will look a
particular way, mentally (or literally) walk your `depends_on` chain
and identify where the plain-dependency runs break. Test in Gazebo/RViz
and *watch the actual motion* — don't just trust that the DAG structure
you wrote produces the blend behavior you intended.

---

## 5. Orientation quaternions: the single riskiest thing to get wrong by hand

If your recipe changes orientation (not just position) between steps,
you are almost certainly hand-deriving or hand-composing quaternions.
This is the highest-risk part of recipe authoring — a sign error
produces a quaternion that is still perfectly unit-norm (so nothing
in validation catches it) but physically wrong, and the failure mode
is often a confusing downstream error (an IK failure or a "leg
generation failed" several steps later) rather than an obvious
rejection at load time.

**Concrete example from real debugging:** a recipe intended "rotate
tool axis 90° about world Y, so it points from tool-down to world +X."
The Hamilton product was composed correctly in form, but a sign was
flipped, producing a quaternion that instead pointed the tool at world
**−X** — unit-norm, loads fine, but the arm was then commanded to
translate toward +X while facing −X, causing an unreachable/awkward
IK target several steps into a merged run.

**Best practices:**
1. **Always state your orientation convention in a YAML comment** at
   the top of the file — e.g. `qx=0,qy=1,qz=0,qw=0 = tool-down`. Every
   derived quaternion should be documented as a delta from that
   baseline, in plain English ("90° about world Z from tool-down").
2. **Never trust a numerically-unit-norm quaternion as evidence of
   correctness.** Unit-norm only proves you didn't make an arithmetic
   error in normalization — it says nothing about whether the rotation
   axis/sign/direction is what you intended.
3. **Verify visually before trusting physically.** Load the recipe,
   step to the pose in RViz (or via the interactive marker in planner
   mode — see Section 8), and *look at which way the tool is actually
   facing* before running the recipe against real hardware or even
   trusting the sim result blindly.
4. **Test the rotation axis in isolation** if you're unsure: apply the
   candidate quaternion to the tool's local +Z (or whatever your
   approach axis is) via a rotation-matrix sanity check, and confirm
   the resulting world-frame vector matches your stated intent, before
   pasting the quaternion into the recipe.

---

## 6. YAML gotchas that will crash or silently corrupt your recipe

- **Bare `on`/`off` as command values parse as YAML booleans (`True`/
  `False`), not strings.** `command: on` in a recipe step is *not* the
  string `"on"` — always quote it: `command: "on"`. The compiler now
  hardens against this at the type level (`str()`-coerces identifier/
  command fields), so a bad value won't crash the whole orchestrator
  process anymore — but it will still silently misbehave at the tool
  backend if the string doesn't match what the backend expects. Quote
  it anyway; don't rely on the hardening as your only defense.
- **Quote anything that could be YAML-ambiguous:** `yes`/`no`, `null`,
  numeric-looking strings, etc. If in doubt, quote it.
- **A malformed multi-line scalar silently continues onto the next
  line.** Watch line-wrapping in your editor — a stray line break
  inside a `target_pose: {...}` block can produce a value that still
  parses (most YAML parsers rejoin it) but isn't what you see rendered
  in a narrow editor window. Double-check wide/unwrapped view before
  trusting a copy-pasted pose block.

---

## 7. Recovery policies — write them deliberately, not as an afterthought

Every `tool`/`io` step (and by extension the motion leg it's part of)
can declare:

```yaml
recovery: retry        # or: degrade | hold | abort (default if unspecified)
max_retries: 2
```

- **`retry`**: re-dispatches the same step up to `max_retries` times on
  failure. Good for transient issues (a gripper controller hiccup,
  momentary comms blip). **Bad for anything where the failure is
  deterministic** — e.g. an IK failure from a genuinely unreachable
  pose will fail identically every retry, just burning time before
  falling through anyway. Reserve `retry` for genuinely
  possibly-transient hardware/comms failures, not logic errors.
- **`degrade`**: treats the step as completed despite failure, letting
  the DAG continue. Only appropriate where continuing without that
  step's confirmed success is actually safe for your process — e.g. an
  optional blow-off step, not a grip-close before a placement.
- **`hold`**: leaves the step pending for operator intervention, i.e.
  a natural fit for anything that needs a human to look before
  continuing.
- **Default (no recovery / anything unmatched)**: aborts the whole
  recipe run. This is the safest default and should be your baseline
  for anything safety- or correctness-critical (grips before a
  transfer, insertions, anything that could damage a part or the
  robot if silently skipped).

**Practical guidance:** default to no `recovery` field (abort) unless
you have a specific, considered reason to retry/degrade/hold. Recovery
policy is a safety decision, not a convenience default.

---

## 8. Planning waypoints instead of hand-deriving them

Given how error-prone hand-derived quaternions are (Section 5), prefer
capturing real waypoints via the interactive marker in **PLANNER**
mode rather than typing pose numbers from memory or hand-computed
math wherever practical:

1. Switch the cell to `PLANNER` mode — the marker appears at the
   current pose and is fully isolated from `ACTIVE`/execution (both by
   visibility and by an independent mode check on the pose pipeline —
   a stray marker interaction cannot reach the real robot).
2. Drag the marker to the pose you want; the IK solve previews live in
   RViz so you see the actual resulting configuration before
   committing to anything.
3. Right-click → **Capture Waypoint** to record the exact pose (in the
   same `x,y,z,qx,qy,qz,qw` shape your recipe's `target_pose:` fields
   use) instead of deriving it by hand.
4. **Write captured waypoints to file** to dump them to a per-recipe
   YAML you can paste directly into your recipe's `target_pose` blocks.

This sidesteps the entire class of sign/convention errors from Section
5 for any waypoint that corresponds to a real, physically-reachable
pose you can actually jog to.

---

## 9. Testing workflow (do this every time, not just for new recipes)

1. **Load, don't just author.** `load_recipe` validates `depends_on`
   references and cycle-freedom before anything runs — a clean load
   doesn't mean a correct recipe, but a failed load catches structural
   errors for free. Always load before assuming the YAML is sound.
2. **Simulate before hardware, every single time — including small
   edits.** A one-line quaternion or `blend_radius` change can alter
   which steps get merged into a single motion run; re-verify the
   whole affected sequence, not just the line you changed.
3. **Watch the motion, not just the log.** The DAG log tells you steps
   completed in the right order; it does not tell you whether the
   *path* looked right (Section 4) or whether an orientation was
   physically correct (Section 5). RViz/Gazebo visual confirmation is
   not optional for any recipe involving reorientation or precision
   insertion.
4. **Test single-station before multi-station.** Validate one
   pick/place cycle in isolation before composing a multi-station
   recipe — merged-run detection and recovery policies compound across
   a longer chain, and isolating a single cycle makes root-causing far
   faster if something's wrong.
5. **Re-run the same recipe multiple times in the same session before
   calling it done.** Some classes of bugs (stale action-server
   responses, per-tool serialization edge cases, orphaned processes)
   only surface on the 2nd/3rd run, not the first — a recipe that works
   once is not yet a recipe that works reliably.

---

## 10. Quick pre-flight checklist

Before running a new or edited recipe:

- [ ] Every `command:` value that could be `on`/`off`/`yes`/`no` is
      quoted as a string.
- [ ] Every `move` step choosing between `js`/`ts` matches the
      guidance in Section 2 (traverse vs. touch/approach).
- [ ] Every reorientation quaternion has a plain-English comment
      stating the intended rotation, and has been visually verified
      (RViz/marker), not just checked for unit-norm.
- [ ] `depends_on` chains have been mentally walked to confirm which
      `move` steps will merge, and that matches the blend/stop
      behavior you actually want.
- [ ] `recovery`/`max_retries` on every `tool`/`io` step is a
      deliberate choice, not a default left unconsidered.
- [ ] Progress-dependency thresholds make sense for the actuation time
      of the tool involved.
- [ ] The recipe has been loaded, simulated, visually confirmed, and
      re-run at least twice in the same session without a fresh
      restart of the node stack.
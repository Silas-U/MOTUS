"""
resource_lock.py

Plain named-mutex map for cross-arm contention (a shared handoff zone,
a shared tool, a no-go volume). One holder per resource name, FIFO
waiters, no timeouts, no priority. If a recipe needs more than this,
the recipe is asking for too much — not this lock.
"""

from typing import Dict, List


class ResourceLock:
    def __init__(self):
        self._holder: Dict[str, str] = {}
        self._waiters: Dict[str, List[str]] = {}

    def try_acquire(self, resources: List[str], owner_id: str) -> bool:
        """All-or-nothing. Returns True iff every named resource was free
        (or already held by owner_id) and is now held by owner_id."""
        if not resources:
            return True
        for r in resources:
            holder = self._holder.get(r)
            if holder is not None and holder != owner_id:
                for r2 in resources:
                    waiters = self._waiters.setdefault(r2, [])
                    if owner_id not in waiters:
                        waiters.append(owner_id)
                return False
        for r in resources:
            self._holder[r] = owner_id
        return True

    def release(self, resources: List[str], owner_id: str) -> List[str]:
        """Releases resources held by owner_id. Returns the set of step_ids
        that were waiting on any of them — caller re-checks each one's own
        full resource list before actually dispatching it."""
        unblocked = set()
        for r in resources:
            if self._holder.get(r) == owner_id:
                del self._holder[r]
            for w in self._waiters.get(r, []):
                unblocked.add(w)
            self._waiters[r] = []
        return list(unblocked)
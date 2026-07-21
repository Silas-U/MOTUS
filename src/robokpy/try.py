# import numpy as np
# from robokpy import Init_Model

# # Load the same URDF your nodes use
# with open('/home/meta/Documents/robotics_workspace/src/robokpy_controller/urdf/ur5e_virtual.urdf', 'r') as f:
#     urdf_str = f.read()

# model = Init_Model(urdf_str, base_link='world', tip_link='tcp')
# ik = model.ik
# fk = model.fk

# # Use the SAME joint config your robot was at when you captured
# # the tf2_echo / home_pose output earlier
# q_current = np.array([1.5697, -2.0535, 1.9318, -1.4490, -1.5707, 0.0])  # your home_pose from YAML

# # Confirm FK still matches what you saw
# # fk.compute_chain(q_current, 'world', 'tcp')
# # print("FK check:", fk.get_pose_quart())

# # # Target = the tf2_echo-verified pose
# # target = np.array([-0.13300, 0.29200, 0.38300, 1.000, -0.001, -0.000, 0.000])

# # q_sol = ik.solve(target, q0=q_current, mask=[1,1,1,1,1,1])

# # print("IK success:", ik.success)
# # print("IK final error:", ik.last_err)
# # print("Solved q:", q_sol)
# # print("Original q:", q_current)
# # print("Match:", np.allclose(q_sol, q_current, atol=1e-2))


# # Test 2: solve to a different orientation, same rough position
# target_reoriented = np.array([-0.133, 0.292, 0.383,  0.0, 0.7071, 0.0, 0.7071])  # tool pointing sideways, arbitrary example
# q_sol2 = ik.solve(target_reoriented, q0=q_current, mask=[1,1,1,1,1,1])
# print("IK success (reoriented):", ik.success)
# print("IK final error (reoriented):", ik.last_err)
# print("Solved q (reoriented):", q_sol2)

# fk.compute_chain(q_sol2, 'world', 'tcp')
# print("FK of solved q:", fk.get_pose_quart())
# print("Target was:    ", target_reoriented)
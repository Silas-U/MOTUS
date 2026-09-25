import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/meta/Documents/robotics_workspace_new/ur5e_test/install/ur5e_test_motus'

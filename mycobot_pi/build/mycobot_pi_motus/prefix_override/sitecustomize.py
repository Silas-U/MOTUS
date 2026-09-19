import sys
if sys.prefix == '/usr':
    sys.real_prefix = sys.prefix
    sys.prefix = sys.exec_prefix = '/home/meta/Documents/robotics_workspace_new/mycobot_pi/install/mycobot_pi_motus'

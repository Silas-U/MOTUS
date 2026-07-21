# """
# Author: Silas Udofia
# Date: 2024-08-02
# GitHub: https://github.com/Silas-U/RoboKpy/tree/main

# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at: http://www.apache.org/licenses/LICENSE-2.0
# """

from .model import URDFModel
from .fk import ForwardKinematics
from .ik import InverseKinematics
from .jacobian import Jacobian
from .trajectory import TrajectoryPlanner


class Init_Model:
    """High level API wrapping."""
    def __init__(self, urdf_str):
        self.model = URDFModel(urdf_str, from_string=True)
        self.fk = ForwardKinematics(self.model)
        self.jacobian = Jacobian(self.model, self.fk)
        self.ik = InverseKinematics(self.model, self.fk,  self.jacobian)
        self.traj = TrajectoryPlanner(self.model, self.fk, self.ik, self.jacobian)
    
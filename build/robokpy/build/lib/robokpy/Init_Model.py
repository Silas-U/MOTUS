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
    def __init__(self, urdf_str, base_link="world", tip_link="tcp", ik=None):
        """
        Args:
            urdf_str: URDF XML string.
            base_link: Root link of the planning chain.
            tip_link:  End-effector link of the planning chain.
            ik: Optional injected IK backend. If None, the default
                RoboKpy InverseKinematics is used.  If provided,
                it must satisfy the IKSolverBackend interface.
        """
        self.model    = URDFModel(urdf_str, from_string=True)
        self.fk       = ForwardKinematics(self.model)
        self.jacobian = Jacobian(self.model, self.fk)

        self._validate_link(base_link)
        self._validate_link(tip_link)

        if ik is None:
            self.ik = InverseKinematics(
                self.model, self.fk, self.jacobian,
                base_link=base_link, tip_link=tip_link
            )
        else:
            self.ik = ik
            self.ik.base_link = base_link
            self.ik.tip_link  = tip_link

        # TrajectoryPlanner receives the same ik reference — crucial
        # so that motion_planner._generate_leg() uses the backend
        # solver, not a stale RoboKpy instance.
        self.traj = TrajectoryPlanner(self.model, self.fk, self.ik, self.jacobian)

        self.chains = {"default": (base_link, tip_link)}
        self.base_link = base_link
        self.tip_link  = tip_link

        # Whole-model joint registry for rendering / reporting
        self.all_joint_names = self.model.get_joint_names()

    def _validate_link(self, link_name: str):
        if link_name not in self.model.get_link_names():
            raise ValueError(
                f"planning link '{link_name}' not found in URDF. "
                f"Available: {self.model.get_link_names()}"
            )

    def add_chain(self, name: str, base_link: str, tip_link: str):
        self._validate_link(base_link)
        self._validate_link(tip_link)
        self.chains[name] = (base_link, tip_link)

    def set_active_chain(self, name: str):
        base_link, tip_link = self.chains[name]
        self.ik.base_link = base_link
        self.ik.tip_link   = tip_link
        self.base_link = base_link
        self.tip_link  = tip_link

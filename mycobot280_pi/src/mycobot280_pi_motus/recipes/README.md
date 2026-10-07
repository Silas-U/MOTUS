# Recipes

Project recipes (YAML). They are installed with this package and found by the
orchestrator before robokpy_controller's own examples:

    ros2 run robokpy_controller run_recipe my_recipe.yaml

Recipe poses encode THIS robot's reach and TCP, so keep them here rather than
in robokpy_controller. See robokpy_controller's recipe authoring guide for the
step format.

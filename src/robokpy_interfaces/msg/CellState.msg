uint8 IDLE=0
uint8 PLANNING=1
uint8 EXECUTING=2
uint8 PAUSED=3
uint8 ERROR=4
uint8 ESTOP=5

uint8 state
string active_recipe_id
string last_error
builtin_interfaces/Time stamp
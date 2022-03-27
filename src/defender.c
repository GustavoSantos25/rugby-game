// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "defender.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_defender_strategy(
    position_t defender_position, Spy attacker_spy) {
    UNUSED(attacker_spy);

  // In C, static variables are kept between executions of the function
  // By construction, the attacker will never be in the INVALID_POSITION,
  // so this works to initialize the variable.
  static position_t previous_position = INVALID_POSITION;
  direction_t directions[2] = {DIR_UP, DIR_DOWN};
  static direction_t best_direction;
  static int best_direction_index = 0;

  if(equal_positions(defender_position, previous_position)){
    best_direction_index = (best_direction_index+1)%2;
  }

  best_direction = directions[best_direction_index];
  previous_position = defender_position;
  return best_direction;
}

/*----------------------------------------------------------------------------*/

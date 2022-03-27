// Standard headers
#include <stdio.h>

// Internal headers
#include "direction.h"
#include "position.h"
#include "spy.h"

// Main header
#include "attacker.h"

// Macros
#define UNUSED(x) (void)(x) // Auxiliary to avoid error of unused parameter

/*----------------------------------------------------------------------------*/
/*                              PRIVATE FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

int check_way(int dir_ind, int number_of_directions, int cur_way){
  int way = cur_way;
  if(dir_ind == 0) way = 1;
  else if(dir_ind == number_of_directions - 1) way = 0;
  return way;
}

int change_direction_index(int prev_dir_ind, int cur_way){
  int ind;
  if(cur_way == 1) ind = prev_dir_ind + 1;
  else return ind = prev_dir_ind - 1;
  return ind;
}


/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/*                              PUBLIC FUNCTIONS                              */
/*----------------------------------------------------------------------------*/

direction_t execute_attacker_strategy(
    position_t attacker_position, Spy defender_spy) {
// TODO: unused parameters, remove these lines later
  UNUSED(defender_spy);
  
  static position_t previous_position = INVALID_POSITION;
  direction_t directions[5] = {DIR_DOWN, DIR_DOWN_RIGHT, DIR_RIGHT, DIR_UP_RIGHT, DIR_UP};
  static direction_t best_direction;
  static int best_direction_index = 1;
  static int previous_direction_index;
  static int current_way = 1;
 

  if (equal_positions(attacker_position, previous_position)) {
    current_way = check_way(previous_direction_index, 5, current_way);
    best_direction_index = change_direction_index(previous_direction_index, current_way);
  }

  best_direction = directions[best_direction_index];
  
  previous_direction_index = best_direction_index;
  previous_position = attacker_position;
  return best_direction;
}

/*----------------------------------------------------------------------------*/

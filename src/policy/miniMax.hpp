#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for miniMax policy, 
 * your policy class should have get_move method
 */
class miniMax{
public:
  static Move get_move(State *state, int depth);
  static int MMSearch(State *state, int depth, int maximizingPlayer);
};
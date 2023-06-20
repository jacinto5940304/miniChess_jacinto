#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for miniMax policy, 
 * your policy class should have get_move method
 */
class alphabeta{
public:
  static Move get_move(State *state, int depth);
  static int APSearch(State *state, int depth, int maximizingPlayer, int ap, int bt);
};
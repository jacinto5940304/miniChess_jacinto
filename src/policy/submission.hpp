#pragma once
#include "../state/state.hpp"


/**
 * @brief Policy class for miniMax policy, 
 * your policy class should have get_move method
 */
class submission{
public:
  static Move get_move(State *state, int depth);
  static int submission_APSearch(State *state, int depth, int maximizingPlayer, int ap, int bt);
};
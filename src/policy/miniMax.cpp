#include <cstdlib>
#include "../state/state.hpp"
#include "./miniMax.hpp"
/**
 * @brief miniMax get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

int init_player;
Move miniMax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  Move nextMove;
  int max = INT_MIN;
  int min = INT_MAX;
  init_player = state->player;
  if(init_player == 0){
    for(auto child : state->legal_actions){
      int childValue = MMSearch(state->next_state(child), depth-1, !state->player);
      if(childValue > max){
        max = childValue;
        nextMove = child;
      }
    }
  }
  else{
    for(auto child : state->legal_actions){
      int childValue = MMSearch(state->next_state(child), depth-1, !state->player);
      if(childValue < min){
        min = childValue;
        nextMove = child;
      }
    }
  }
  // int parentValue = miniMax::MMSearch(state, depth, state->player);

  return nextMove;      // not used
}

int miniMax::MMSearch(State *state, int depth, int maximizingPlayer){
  int retValue = 0;
  if(depth == 0||!state->legal_actions.size()) return retValue = state->evaluate();
  // if (!state->legal_actions.size()) state->get_legal_actions();

  // std::cout << state->player << ' ' << maximizingPlayer << '\n';
  if(maximizingPlayer == 0){
    retValue = INT_MIN;
    for(auto child : state->legal_actions){
      State *newState = state->next_state(child);
      retValue = std::max(retValue, MMSearch(newState, depth-1, !maximizingPlayer));
      //return retValue;
    }
  }
  else{
    retValue = INT_MAX;
    for(auto child : state->legal_actions){
      State *newState = state->next_state(child);
      retValue = std::min(retValue, MMSearch(newState, depth-1, !maximizingPlayer));
      //return retValue;
    }
  }

  return retValue;        // not used
}
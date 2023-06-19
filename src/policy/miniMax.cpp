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
Move miniMax::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  int parentValue = miniMax::MMSearch(state, depth, state->player);
  for(auto child : state->legal_actions){
    int childValue = miniMax::MMSearch(state->next_state(child), depth-1, 1-state->player);
    if(parentValue == childValue){
      return child;
    }
  } //0:先攻 第一個指令
  return state->legal_actions[(rand()+depth)%state->legal_actions.size()];      // not used
}

int miniMax::MMSearch(State *state, int depth, int maximizingPlayer){
  int retValue = 0;
  if(depth == 0) return retValue = state->evaluate();
  // if (!state->legal_actions.size()) state->get_legal_actions();           // not every child node have been searched



  if(maximizingPlayer){
    retValue = INT_MIN;
    for(auto child : state->legal_actions){
      State *newState = state->next_state(child);
      retValue = std::max(retValue, MMSearch(newState, depth-1, 1-maximizingPlayer));
      return retValue;
    }
  }
  else{
    retValue = INT_MAX;
    for(auto child : state->legal_actions){
      State *newState = state->next_state(child);
      retValue = std::min(retValue, MMSearch(newState, depth-1, 1-maximizingPlayer));
      return retValue;
    }
  }

  return retValue;        // not used
}
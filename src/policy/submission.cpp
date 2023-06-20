#include <cstdlib>
#include "../state/state.hpp"
#include "./submission.hpp"
/**
 * @brief submission get a legal action
 * 
 * @param state Now state
 * @param depth You may need this for other policy
 * @return Move 
 */

int init_player;
Move submission::get_move(State *state, int depth){
  if(!state->legal_actions.size())
    state->get_legal_actions();
  Move nextMove;
  int max = INT_MIN;
  int min = INT_MAX;
  int alpha = INT_MIN;
  int beta = INT_MAX;
  init_player = state->player;
  if(init_player == 0){
    for(auto child : state->legal_actions){
      int childValue = submission_APSearch(state->next_state(child), depth-1, !state->player, alpha, beta);
      if(childValue > max){
        max = childValue;
        nextMove = child;
      }
    }
  }
  else{
    for(auto child : state->legal_actions){
      int childValue = submission_APSearch(state->next_state(child), depth-1, !state->player, alpha, beta);
      if(childValue < min){
        min = childValue;
        nextMove = child;
      }
    }
  }
  // int parentValue = submission::APSearch(state, depth, state->player);

  return nextMove;      // not used
}

int submission::submission_APSearch(State *state, int depth, int maximizingPlayer, int ap, int bt){
  int retValue = 0;
  if(!depth||!state->legal_actions.size()) return retValue = state->evaluate();
  // if (!state->legal_actions.size()) state->get_legal_actions();

  // std::cout << state->player << ' ' << maximizingPlayer << '\n';
  if(!maximizingPlayer){
    retValue = INT_MIN;
    for(auto child : state->legal_actions){
      State *newState = state->next_state(child);
      retValue = std::max(retValue, submission_APSearch(newState, depth-1, !maximizingPlayer, ap, bt));
      ap = std::max(ap, retValue);
      if(ap >= bt) break;
      //return retValue;
    }
  }
  else{
    retValue = INT_MAX;
    for(auto child : state->legal_actions){
      State *newState = state->next_state(child);
      retValue = std::min(retValue, submission_APSearch(newState, depth-1, !maximizingPlayer, ap, bt));
      bt = std::min(bt, retValue);
      if(bt <= ap) break;
      //return retValue;
    }
  }

  return retValue;        // not used
}

//
#include "../deck_config.h"
#include "../types/types.h"
#include "ccard_ai.h"
//
/*calculates the sum of values*/
int set_sum(card_t *set) {
  int ssum = 0;
  for (int i = 0; i < SET_MAX; i++) {
    if (set[i].val == -1) {
      break;
    } else { 
      ssum += set[i].val;
    }
  }
  return ssum;
}
/*takes in its player[i] struct and player moves,deck count and the amount of common card */

int ai_move(player_t ai, int other_moves, player_t pl,int empt ) {
  int aiSetSum = set_sum(ai.player_set), playerCardCount = pl.cards_in_set;
  empt--;
  /*
    All of the moves for an AI
    1. give up
    2. add card to set
    3. pass
    0. fail!
  */
  if (aiSetSum == 0) {
    return 0;
  }
  if (aiSetSum >= 20 || aiSetSum == 21) {
    return 1;
  }
  if (aiSetSum < 20 ) {
    return 2;
  }
  if (aiSetSum < 21 && other_moves == 2) {
    return 3;
  }
  if (aiSetSum < 21 && other_moves == 3) {
    return 2;
  }
}
/*calculates bool sums*/
bool bool_sum(bool *a, int sz) {
  int blS = 0;
  for (int i = 0; i < sz - 1 ; i++) {
    blS += a[i];
  }
  return (bool)blS;
}
/*returnes the max one out of the leaderboard of bots*/ 
int max(bot_ld *a, int sz) {
  int mx = 0;
  for (int hlp = 0; hlp < sz; hlp++) {
    if (mx < a[hlp].sum)
      mx = a[hlp].sum;
  }
  return mx;
}
/*returnes the name of a bot that has the max value*/ 
char max_name(bot_ld *o, int sz,int mx) {
  for (int i = 0;i < sz; i++) {
    if(++o->sum == mx)
      return o->name;
  }
}
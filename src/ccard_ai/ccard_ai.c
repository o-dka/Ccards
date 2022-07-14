#include <stdlib.h>
#include <stdio.h>
#include "../types/types.h"
#include "../general_logic/general_logic.h"
#include "../deck_config.h"
#include "ccard_ai.h"
int set_sum (card_t *set) {
  int ssum = 0;
  for (int i = 0; i < SET_MAX;i++) {
    if (set[i].val == -1) {
      break;
    }
    else{
      ssum+=set[i].val;
    }
  }
  return ssum;
}
void give_up(int ac,char* s,int num_ai) {  // the player r Ai 
  printf("%s gives up, my sum is %d\n",s,ac,num_ai);
}

int ai_move(player_t p,int other_moves) { 
  /*
  1. give up
  2. add card to set
  3. pass
  0. fail
  */ 
  
  return 0;
}
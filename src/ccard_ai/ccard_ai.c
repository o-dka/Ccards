#include <stdlib.h>
#include <stdio.h>
//
#include "../types/types.h"
#include "../deck_config.h"
#include "ccard_ai.h"
//
/*calculates the sum of a set*/ 
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
/* takes in the sum , the name of and the number of a player/AI */ 
void give_up(int ac,char* s,int num_ai) {  
  printf("%s%i gives up, my sum is %d\n",s,num_ai,ac);
}
/*takes in its player[i] struct and player moves*/ 
int ai_move(player_t p,int other_moves) {  
  int aiSetSum = set_sum(p.player_set);

  /*
  All of the moves for an AI
  1. give up
  2. add card to set
  3. pass
  */ 
 if ( aiSetSum == 0){
  return 0; 
 }
  if (aiSetSum > 20 || aiSetSum == 21){
    return 1;
  }
  if(aiSetSum < 10){
    return 2;
  }
  if(aiSetSum < 21 && other_moves == 2){
    return 3;
  }
  if (aiSetSum < 21 && other_moves == 3){
   return 2;
  }
}
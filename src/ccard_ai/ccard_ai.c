#include <stdlib.h>
#include "ccard_ai.h"
int set_sum (card_t *set){
  int sum = 0;
  for (int i = 0; i < SET_MAX;i++){
    if (set[i].val == -1){
      break;
    }
    else{
      sum+=set[i].val;
    }
  }
  return sum;
}
void give_up(void){}
void take_card(void){}
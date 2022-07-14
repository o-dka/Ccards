#include "../types/types.h"
//
#ifndef __CCARD_AI_H__
#define __CCARD_AI_H__

int set_sum(card_t *set);
void give_up(int a,char* s,int num_ai);
int ai_move(player_t p,int other_moves);

#endif // __CCARD_AI_H__
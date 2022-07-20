#include "../types/types.h"
//
#ifndef __CCARD_AI_H__
#define __CCARD_AI_H__

int set_sum(card_t *set);
int ai_move(player_t p, int other_moves); 
bool bool_sum(bool *a,int sz);
int max(bot_ld *a, int sz);
char max_name(bot_ld *o, int sz, int mx);

#endif // __CCARD_AI_H__
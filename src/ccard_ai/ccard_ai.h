#ifndef __CCARD_AI_H__
#define __CCARD_AI_H__

#include "../types/types.h"
#include <stdbool.h>
int set_sum(card_t *set);
int ai_move(player_t ai, int other_moves, player_t pl, int empt);
bool bool_sum(bool *a, int sz);
int max(bot_ld *a, int sz);
char max_name(bot_ld *o, int sz, int mx);

#endif // __CCARD_AI_H__
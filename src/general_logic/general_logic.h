#include "../types/types.h"
#ifndef __GENERAL_LOGIC_H__
#define __GENERAL_LOGIC_H__
void print_cards(card_t *a, int it);
void fill_deck(card_t *deck);
void shuffle_deck(card_t *deck, player_t *p,int cards_to_add);
int sum_cards();
int empt(card_t *p,int size);
void fill_set(card_t *set);
#endif // __GENERAL_LOGIC_H__
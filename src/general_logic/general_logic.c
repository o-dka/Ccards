#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// other
#include "../deck_config.h"
#include "../types/types.h"
// local
#include "general_logic.h"



void print_cards(card_t *a, int it) {
  for (int o = 0; o < it; o++)
    printf(DISPLAY_CARD, a[o].val, a[o].name, a[o].val);
}
int empt(card_t *p,int size ){
  static int itr = 0;
  for (; itr < size ;itr++){
    if (p[itr].val == -1){
      return itr; 
    }
  }
}
void fill_deck(card_t *deck) {
  int x_c = 1, x_v = 0; // iterators for cards,values
  const int vals[VALS_SIZE] = VALS;
  const char names[4] = NAMES;
  for (; x_c != NUM + 1; x_c++, x_v++) // this CAN be done better, but idc
  {
    x_v = x_v > (VALS_SIZE - 1) ? 0 : x_v; // restarts the position of the value iterator if it's past the array size
    deck[x_c - 1].name = names[(x_c - 1) / 9];
    deck[x_c - 1].val = vals[x_v];
  }
}

void shuffle_deck(card_t *deck, player_t *p,int cards_to_add) {
  static int deck_rand_count = NUM - 1;
  static  int deck_index  = 0;
  for(;cards_to_add>0;cards_to_add--) {
    FILL:
		srand(time(0));
		deck_index = rand() % deck_rand_count;
    if (deck[deck_index].val != -1) {
      p->player_set[empt(p->player_set,SET_MAX)] = deck[deck_index];
      deck[deck_index].val = -1; 
    }
    else { 
      goto FILL;
    }
  }
}
void fill_set (card_t *set){
	for (int i = 0 ; i != SET_MAX ;i++){
		set[i].val = -1;
		set[i].name = 'X';
	}
}

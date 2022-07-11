#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// other
#include "../deck_config.h"
#include "../types/types.h"
// local
#include "general_logic.h"

char *empty_card = "   ------- \n  |%i      | \n  |   %c   | \n  |      %i| \n   ------- \n"; //cli pretty thing

void print_struct(card_t *a, int it) {
  for (int o = 0; o < it; o++)
    printf(empty_card, a[o].val, a[o].name, a[o].val);
}

void fill_deck(card_t *deck) {
  int x_c = 1, x_v = 0; // iterators for cards,values
  static const int vals[VALS_SIZE] = VALS;
  static const char names[4] = NAMES;
  for (; x_c != NUM + 1; x_c++, x_v++) // this CAN be done better, but idc
  {
    x_v = x_v > (VALS_SIZE - 1) ? 0 : x_v; // restarts the position of the value iterator if it's past the array size
    deck[x_c - 1].name = names[(x_c - 1) / 9];
    deck[x_c - 1].val = vals[x_v];
  }
}
void shuffle_deck(card_t *deck, player_t *p) {
	

}

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
int empt(card_t *p, int size) {
  int itr = 0;
  for (; itr < size; itr++) {
    if (p[itr].val == -1) {
      return itr;
    }
  }
  return -1;
}
void fill_deck(card_t *deck) {
  int itC = 1, itV = 0,itH = 0; // iterators for cards,values,chars
  const int vals[VALS_SIZE] = VALS;
  const  char names[NAMES_SIZE] = NAMES;
  for (; itC != NUM + 1; itC++, itV++,itH++) // this CAN be done better, but idc
  {
    /*restarts the position of the value iterator if it's past the array size*/
    itV = itV > (VALS_SIZE - 1) ? 0 : itV;
    itH = itH > (NAMES_SIZE - 1) ? 0 : itH;
    /* works only if NUM  is eq to 36, need to find a general-ish way of doing
     * this later */
    deck[itC - 1].name = names[itH];
    deck[itC - 1].val = vals[itV];
  }
}

int shuffle_deck(card_t *deck, player_t *p, int cards_to_add) {
  int deckIndex = 0;
  for (int i = cards_to_add; i != 0; i--, ++p->cards_in_set) {
  FILL:
    srand(time(0));
    deckIndex = rand() % (NUM - 1);
    if (deck[deckIndex].val != -1 && (empt(p->player_set, SET_MAX) != -1)) {
      p->player_set[empt(p->player_set, SET_MAX)] = deck[deckIndex];
      deck[deckIndex].val = -1;
    } else if (empt(p->player_set, SET_MAX) == -1) {
      printf("No more card space, give up !");
      return 0;
    } else {
      goto FILL;
    }
  }
  return 1;
}
void fill_set(card_t *set) {
  for (int i = 0; i != SET_MAX; i++) {
    set[i].val = -1;
    set[i].name = 'X';
  }
}
void zero_pl(player_t *p, int a) {
  for (int i = 0; i < a; i++, p++) {
    fill_set(p->player_set);
    p->cards_in_set = 0;
  }
}
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <wchar.h>
// other
#include "../deck_config.h"
#include "../types/types.h"
// local
#include "general_logic.h"

void print_cards(card_t a, int it) { 
  for (int o = 0; o < it; o++)
   printf(DISPLAY_CARD, a[o].val, a[o].name, a[o].val);
}
/*checks if the index of player_set if empty or not*/ 
int empt(card_t *p, int size) {
  int itr = 0;
  for (; itr < size; itr++) {
    if (p[itr].val == -1) {
      return itr;
    }
  }
  return -1; // returns error if not any empty indexes found
}
/* fills the deck of card_t*/ 
void fill_deck(card_t *deck) {
  int itC = 1, itV = 0, itH = 0; // iterators for cards,values,chars
  const int vals[VALS_SIZE] = VALS;
  wint_t names[NAMES_SIZE] = NAMES;
  // this CAN be done better, but whatever
  for (; itC != NUM + 1; itC++, itV++, itH++) 
  {
    /*restarts the position of the iterator(s) if it's past the array size*/
    itV = itV > (VALS_SIZE - 1) ? 0 : itV;
    itH = itH > (NAMES_SIZE - 1) ? 0 : itH;
    deck[itC - 1].name = names[itH];
    deck[itC - 1].val = vals[itV];
  }
}
/*
* Adds a card to the player_set
* this fucntion is cool, but innefficent
*/
int shuffle_deck(card_t *deck, player_t *p, int cards_to_add) {
  int deckIndex = 0; // initializes the index
  for (int i = cards_to_add; i != 0; i--, ++p->cards_in_set) {
  FILL:
    srand(time(0));
    deckIndex = rand() % (NUM - 1); // randomises it to fit the index def 0..35
    /*
    * figures out if deck val of that index is not empty,
    *  checks if the player_set is empty
    */
    if (deck[deckIndex].val != -1 && (empt(p->player_set, SET_MAX) != -1)) {
      /* finds the empty index in the player_set and assigns a value to it */
      p->player_set[empt(p->player_set, SET_MAX)] = deck[deckIndex];
      deck[deckIndex].val = -1; // empties out the assigned val in deck

    } /*if player_set not empty, throws an error*/
    else if (empt(p->player_set, SET_MAX) == -1) {
      printf("No more card space, give up !");
      return 0;
    } else { // if the deck index is empty, goes back
      goto FILL;
    }
  }
  return 1;
}
/*fills the sets with garbage values, that no one should add as configs*/
void fill_set(card_t *set) {
  for (int i = 0; i != SET_MAX; i++) {
    set[i].val = -1;
    set[i].name = 'X';
  }
}
/*"zeroes out the player_t values"*/
void zero_pl(player_t *p, int a) {
  for (int i = 0; i < a; i++, p++) {
    fill_set(p->player_set);
    p->cards_in_set = 0;
  }
}
/* takes in the sum , the name of and the number of a player/AI */
void give_up(int ac, char *s, int num_ai) {
    printf("%s%i gives up, their sum is %d\n", s, num_ai, ac);
}
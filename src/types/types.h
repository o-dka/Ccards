#include "../deck_config.h"
#ifndef __TYPES_H__
#define __TYPES_H__

typedef struct card_t card_t;
struct card_t {
  short int val;
  unsigned char name;
};

typedef struct player_t player_t;
struct player_t {
  card_t player_set[SET_MAX]; // limited number of cards(huhahahe)!
  short int points;
  short int cards_in_set;
};

#endif // __TYPES_H__
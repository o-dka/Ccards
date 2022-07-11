#include "../deck_config.h"
#ifndef __TYPES_H__
#define __TYPES_H__

typedef struct card_t card_t;
struct card_t{
  int val;
  char name;
};

typedef struct  player_t player_t;
struct player_t {
  card_t player_set[SET_MAX]; // limited number of cards(huhahahe)!
  short int points;
};


#endif // __TYPES_H__
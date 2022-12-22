#include "../deck_config.h"
#ifndef __TYPES_H__
#define __TYPES_H__
#include <wchar.h>
/*card struct int, char*/ 
typedef struct card_t card_t;
struct card_t {
  short int val;
  wint_t name;
};
/*player struct card_t*, int */ 
typedef struct player_t player_t;
struct player_t {
  card_t player_set[SET_MAX]; // limited number of cards(huhahahe)!
  short int cards_in_set;
};
/*bot leaderboard char, int*/ 
typedef struct bot_ld bot_ld; 
struct bot_ld {
  char name;
  short int sum;
};

#endif // __TYPES_H__
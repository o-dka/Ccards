#ifndef __TYPES_H__
#define __TYPES_H__

typedef struct {
  int val;
  char name;
} card_t;

typedef struct {
  card_t set[9];
  short int points;
} player_t;

#endif // __TYPES_H__
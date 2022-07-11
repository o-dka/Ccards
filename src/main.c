#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
// configs
#include "deck_config.h"
// functions
// #include <Twenty_one_rules.h>
#include "types/types.h"
#include "general_logic/general_logic.h"

main() {
  int player_count = 2;	
  card_t cards[NUM];
  player_t players[player_count];
  fill_deck(cards);
  // shuffle_deck(cards,players); // randomise decks
  // implementation of rules
  print_struct(cards, 2); // cli graphix :3
  // return 0;
}

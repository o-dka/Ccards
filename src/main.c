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
  extern int deck_rand_count;
  int player_count = 2;	
  card_t cards[NUM];
  player_t players[player_count],*p_player = &players[0];
  fill_deck(cards);
  for (;;){
    scanf("%d",player_count);
    for (int i = 0 ; i < player_count ;i++,p_player++){
      shuffle_deck(cards,p_player,2); // randomise decks
    }
    // implementation of rules
    print_cards(cards, 2); // cli graphix :3
  }
  // return 0;
}

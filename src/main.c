#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
// configs
#include "deck_config.h"
// functions
// #include "rules/rules.h"
// #include "ccard_ai/ccard_ai.h"
#include "types/types.h"
#include "general_logic/general_logic.h"

int main() {
  int player_count = 2;	
  card_t cards[NUM];
  player_t players[player_count],*p_player = &players[0];
  fill_deck(cards);
  for (;;){
    for (int i = 0 ; i < player_count ;i++,p_player++){
      shuffle_deck(cards,p_player,2); // randomise player sets
    }
    // implementation of rules
    print_cards(cards, 2); // cli graphix :3
  }
  return 0;
}

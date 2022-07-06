#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
// configs
#include "deck_config.h"
// functions
// #include <Twenty_one_rules.h>
#include "general_logic.h"
#include "card_t.h"



int main()
{
	
	extern card_t cards[NUM];
	fill_deck(cards);
	shuffle_deck(cards);  // randomise deck
	// implementation of rules
	// cli graphix :3
	print_struct(cards,2);
	return 0;
}


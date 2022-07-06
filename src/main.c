#include <stdio.h>
#include <stdlib.h>
// configs
#include "deck_config.h"
// functions
// #include <Twenty_one_rules.h>
// #include <General_logic.h>
struct card {
	int val;
	char name;
};

void print_struct(struct card *a);
void fill_deck(struct card *deck);
void shuffle_deck(struct card *deck);

int main()
{
	struct card cards[NUM];
	fill_deck(cards);
	shuffle_deck(cards);  // randomise deck
	// implementation of rules
	// cli graphix :3
	print_struct(cards);
	return 0;
}
void print_struct(struct card *a)
{
	for (int o = 0; o < NUM; o++) printf("%i. %c || %d \n", o, a[o].name, a[o].val);
}

void fill_deck(struct card *deck)
{
	int x_c = 1, x_v = 0;  // iterators for cards,values
	static const int vals[VALS_SIZE] = VALS;
	static const char names[4] = NAMES;
	for (; x_c != NUM + 1; x_c++, x_v++)  // this CAN be done better, but idc
	{
		x_v = x_v > (VALS_SIZE - 1)
			  ? 0
			  : x_v;  // restarts the position of the value iterator if it's past the array size
		deck[x_c - 1].name = names[(x_c - 1) / 9];
		deck[x_c - 1].val = vals[x_v];
	}
}
void shuffle_deck(struct card *deck) {}

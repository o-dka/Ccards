#pragma once

// -----------------------------
// config for the deck
// I recommend commenting out the defaults and typing in new values
// -----------------------------


#define NUM 36 // number of cards in deck 
#define SET_MAX 9   // max number of cards in one set 
// A typical deck of cards 
// 		6  7  8  9   10  V  D  K  T
#define VALS                          \
	{                                   \
		6, 7, 8, 9, 10, 2, 3, 4, 11 			\
	}
#define VALS_SIZE 9
//						hearts,tiles,crests,pikes
#define NAMES {'h','t','c','p'} // char names
#define DISPLAY_CARD  "   ------- \n  |%i      | \n  |   %c   | \n  |      %i| \n   ------- \n" //cli pretty thing for regular chars 

// #define NAMES {'♥','♦','♣','♠'}  // utf8 names (wchar_t only)
// #define DISPLAY_CARD "   ------- \n  |%i      | \n  |   %ls   | \n  |      %i| \n   ------- \n" //cli pretty thing for fancy chars

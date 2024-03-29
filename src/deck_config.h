#ifndef __DECK_CONFIG_H__
#define __DECK_CONFIG_H__


/* Config for the deck
* I recommend commenting out the defaults and typing in new values
* if you want to change something.
* ====================================================================
* DONT SET A NAME AS X AND A VAL AS -1 THIS WILL BREAK EVERYTHING
* ==================================================================
*/

#define NUM 36    // number of cards in deck
#define SET_MAX 9 // max number of cards in one set
// A typical deck of cards
// 		6  7  8  9   10  V  D  K  T

#define VALS                                                                   \
  { 6, 7, 8, 9, 10, 2, 3, 4, 11 } // must be an int
#define VALS_SIZE 9

  //	hearts,tiles,crests,pikes
  // { 'h', 't', 'c', 'p' } // char icons
  // {L'\x2665',L'\x2666',L'\x2663',L'\x2660'} //wchar icons
#define NAMES                                                                  \
  {L'\x2665',L'\x2666',L'\x2663',L'\x2660'} 
#define NAMES_SIZE 4

#define DISPLAY_CARD                                                           \
  "  ------ \n"                                                               \
  " |%i     | \n"                                                             \
  " |   %lc  | \n"                                                             \
  " |     %i| \n"                                                             \
  "  ------ \n"
// cli card
// change lc to c if using char names
#endif // __DECK_CONFIG_H__
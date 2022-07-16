#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// configs
#include "deck_config.h"
// functions
#include "ccard_ai/ccard_ai.h"
#include "general_logic/general_logic.h"
#include "types/types.h"
/*flushes the input stream of garbo*/
void stream_flush(void) {
  int a;
  while ((a = getchar()) != '\n' && a != EOF) {
  }
}
int main() {
  char answer;
  int playerCount, choice;
  int stat, plSetSum, aiSetSum;
  card_t cards[NUM];
  fill_deck(cards);
BRUH:
  printf("Input the amount of \"players \":");
  if (scanf("%d", &playerCount), playerCount <= 1) {
    printf("What are you doing.\n");
    goto BRUH; // try catch '99 style
  }
  bool cAi[playerCount - 1], choiceB = true;
  bot_ld botWin[playerCount - 1];
  player_t players[playerCount], *Ptplayer = &players[0];
  zero_pl(players, playerCount);           // zeroes out the player's sets
  for (int o = 0; o != playerCount; o++) { // zeroes out the leaderboards
    botWin[o].sum = 0;
    cAi[o] = true;
  }
  /* randomises player's first 2 cards */
  for (int i = 0; i < playerCount; i++, Ptplayer++) {
    shuffle_deck(cards, Ptplayer, 2);
  }
READY:
  printf("First you make a move, then ai, you are  player #0.\n"
         "You play the game until either you or the ai will have their sum "
         "of points be greater than 21.\n"
         "The maximum amount of cards is %i , be mindful of that limitation!\n",
         SET_MAX);
  printf("Are you ready? (y/n) : \n");
  answer = 'n';
  stream_flush();
  scanf("%c", &answer);
  if (answer == 'y') {

    printf("Here are the cards you have been dealt: \n");
    Ptplayer = &players[0];
    print_cards(Ptplayer->player_set, Ptplayer->cards_in_set);
    int x = 1;
    while ((bool_sum(cAi, playerCount) || choiceB) == 1) {
      printf("\n===============");
      printf("Round %d", x);
      printf("===============\n");
      x++;
      if (choiceB == true) {
      CHOICE:
        stream_flush();
        Ptplayer = &players[0];
        printf("Will you:\n"
               "1.Give up(show cards to other players).\n"
               "2.Take a card\n3.Pass\n : ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
          plSetSum = set_sum(players[0].player_set);
          if (plSetSum > 21) {
            printf("The player lost, his val is %d\n", plSetSum);

          } else {
            give_up(plSetSum, "The player#", 0);
          }
          choiceB = false;
          break;
        case 2:
          // the player takes a card;
          printf("*You take a card*\n");
          stat = shuffle_deck(cards, Ptplayer, 1);
          /*checks if the player is trying to overflow an array of cards */
          if (stat == 0) {
            printf("You lost idiot"); // true...
            break;
          }
          print_cards(players[0].player_set, players[0].cards_in_set);
          break;
        case 3:
          printf("*You pass*\n");
          break;
        default:
          printf("There is no option %d,my friend.\n", choice);
          goto CHOICE;
          break;
        }
      } else {
        printf("Player automatically skips, as they showed cards.\n");
      }
      printf("Waiting for ai to make a move\n");
      for (size_t i = 1; i < playerCount; i++) {
        /* sets the position of the pointer to the current one of i */
        Ptplayer = &players[i];
        /*
        * All of the moves for an AI:
        * | 1. give up              |
        * | 2. add a card to set    |
        * | 3. pass                 |
        * --------------------------
        * if something weird happens,
        * ai shuts itself off and the player is defined as the winner.
        */
        if (cAi[i - 1] == true) {
          choice = ai_move(players[i], choice);
          switch (choice) {
          case 1:
            aiSetSum = set_sum(Ptplayer->player_set);
            give_up(aiSetSum, "The Ai#", i);
            /* bot vals get saved into a leaderboard if sum <=21 */
            if (aiSetSum <= 21) {
              for (int o = 1; o < playerCount; o++) {
                if (botWin[o].sum == 0) {
                  botWin[o].sum = aiSetSum;
                  botWin[o].name = (char)i;
                  break;
                }
              }
            }
            cAi[i - 1] = false;
            break;
          case 2:
            stat = shuffle_deck(cards, Ptplayer, 1);
            if (stat == 1)
              printf("The Ai#%d takes a card\n", i);
            else {
              printf("Ai#%d lost, coz its dumb af.\n", i);
              cAi[i - 1] = false;
            }
            break;
          case 3:
            printf("The AI%d passes.\n", i);
            break;
          default:
            printf("Ai fail.\n");
            cAi[i - 1] = false;
            break;
          }
        } else {
          printf("Ai#%d skips, because it showed the cards\n", i);
        }
      }
    }
  } else {
    printf("Say yes when you are!\n");
    goto READY;
  }
  aiSetSum = max(botWin, playerCount);
  if ((plSetSum <= 21) > aiSetSum) {
    printf("Player won !\n");
  } else if (plSetSum < aiSetSum) {
    printf("the Ai#%c won!\n", max_name(botWin, playerCount, aiSetSum));
  } else if ((plSetSum <= 21) && (plSetSum == aiSetSum)) {
    printf("Draw!\n");
  } else if ((plSetSum > 21) && (plSetSum == aiSetSum)) {
    printf("You all lose!!\n");
  }
  return 0;
}

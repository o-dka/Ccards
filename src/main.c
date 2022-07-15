#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
// configs
#include "deck_config.h"
// functions
// #include "rules/rules.h"
#include "ccard_ai/ccard_ai.h"
#include "general_logic/general_logic.h"
#include "types/types.h"
/*flushes the input stream*/
void stream_flush(void) {
  int a;
  while ((a = getchar()) != '\n' && a != EOF) {
  }
}
int main() {
  int playerCount = 2, choice;
  char answer;
  int stat, plSetSum;
  bool end = false;
BRUH:
  printf("Input the amount of players :");
  if (scanf("%d", &playerCount), playerCount <= 1) {
    printf("What are you doing.\n");
    goto BRUH;
  }
  int sumVals[playerCount];
  for (int o = 0; o != playerCount; o++)
    sumVals[o] = 0;
  printf(
      "You will play with %d ai, as I am too lazy to implement local play.\n",
      playerCount - 1);
  card_t cards[NUM];
  player_t players[playerCount], *p_player = &players[0];
  fill_deck(cards);
  zero_pl(players, playerCount);
  for (int i = 0; i < playerCount; i++, p_player++) {
    shuffle_deck(cards, p_player, 2); // randomise player sets
  }
READY:
  printf("Are you ready? (y/n) : \n");
  stream_flush();
  answer = 'n';
  scanf("%c", &answer);
  if (answer == 'y') {
    printf(
        "First you make a move, then ai, you are  player #0.\n"
        "You play the game until the sum of card values is greater than 21.\n"
        "The maximum amount of cards is %i , be mindful of that limitation!",
    SET_MAX);
    printf("Here are the cards you have been dealt: \n");
    p_player = &players[0];
    print_cards(p_player->player_set, SET_MAX); // something is wrong here
    for (int x = 1; end != true; x++) {
      printf("\n===============");
      printf("Round %d", x);
      printf("===============\n");
    CHOICE:
      stream_flush();
      p_player = &players[0];
      printf("Will you:\n"
             "1.Give up(show cards to other players).\n"
             "2.Take a card\n3.Pass\n : ");
      scanf("%d", &choice);
      switch (choice) {
      case 1:
        plSetSum = set_sum(players[0].player_set);
        if (plSetSum > 21) {
          printf("The player lost, his val is %d", plSetSum);
          end = true;
        } else {
          give_up(plSetSum, "The player#", 0);
          for (int o = 0; o != playerCount; o++) {
            if (sumVals[o] != 0)
              sumVals[o] = plSetSum;
          }
        }
        break;
      case 2:
        // the player takes a card;
        printf("*You take a card*\n");
        stat = shuffle_deck(cards, p_player, 1);
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
      printf("Waiting for ai to make a move\n");
      // for (p_player = &players[1];p_player !=
      // &players[playerCount-1];++p_player,i++) {
      // ^^ felt smart writing that
      for (size_t i = 1; i < playerCount; i++) {
        /* sets the position of the pointer to the current one of i */
        p_player = &players[i];

        // printf("%i\n",aiMv); for debbugging
        /*
        All of the moves for an AI:
          1. give up
          2. add a card to set
          3. pass
        --------------------------
        if something weird happens ai shuts itself off and the player is defined
        as the winner
        */
        /* reads the ai_move*/
        switch (ai_move(players[i], choice)) {
        case 1:
          plSetSum = set_sum(p_player->player_set);
          give_up(plSetSum, "The ai#", i);
          if (plSetSum > 21) {
            end = true;
          } else {
            for (int o = 0; o != playerCount; o++) {
              if (sumVals[o] != 0)
                sumVals[o] = plSetSum;
            }
          }
          break;
        case 2:
          stat = shuffle_deck(cards, p_player, 1);
          if (stat == 1)
            printf("The Ai takes a card\n");
          else {
            printf("Ai lost, coz its dumb af.");
            return 1;
          }
          break;
        case 3:
          printf("The AI passes.\n");
          break;
        default:
          printf("Ai fail.\n");
          end = true;
          break;
        }
      }
    }

  } else {
    printf("Say yes when you are!\n");
    goto READY;
  }
  return 0;
}

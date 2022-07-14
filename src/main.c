#include <stdio.h>
#include <stdlib.h>
// configs
#include "deck_config.h"
// functions
// #include "rules/rules.h"
#include "ccard_ai/ccard_ai.h"
#include "types/types.h"
#include "general_logic/general_logic.h"

int main() {
  int player_count = 2,choice;
  char answer ;
  int  stat;
  //  BRUH:
  // printf("Input the amount of players :");
  // if (scanf("%d",&player_count),player_count <= 1){
  //   printf("What are you doing.\n");
  //   goto BRUH;
  // }
  printf("You will play with %d ai, as I am too lazy to implement local play.\n",player_count - 1);
  card_t cards[NUM];
  player_t players[player_count],*p_player = &players[0];
  fill_deck(cards);
  zero_pl(players,player_count);
  for (int i = 0 ; i < player_count ;i++,p_player++){
    shuffle_deck(cards,p_player,2); // randomise player sets
  }
  READY:
  printf("Are you ready? (y/n) : \n");
  answer = 'n';
  scanf("%c",&answer);
  if (answer == 'y'){
    printf("First you make a move, then ai, you are  player #0.\nYou play the game until the sum of card values is greater than 21.\n");
    printf("Here are the cards you have been dealt: \n");
    p_player = &players[0];
    print_cards(p_player->player_set,SET_MAX); //something is wrong here 
    for (int x = 1;;x++){
      printf("\n===============");
      printf("Round %d",x );
      printf("===============\n");
      CHOICE:
      p_player = &players[0];
      printf("Will you:\n1.Give up(show cards to other players).\n2.Take a card\n3.Pass\n : "),scanf("%d",&choice);
      if (choice == 1) { // the player shows cards;
        if (set_sum(players[0].player_set) > 21 ){
          printf("The player lost, his val is %d",set_sum(players[0].player_set));
          break;
        }
        else{
          give_up(set_sum(players[0].player_set),"The player#",0);
        }
      }
      else if (choice == 2) { 
        // the player takes a card;
        printf("*You take a card*\n");
        stat = shuffle_deck(cards,p_player,1);
        if (stat == 0){
          printf("You lost idiot");
          break;
        }
        print_cards(players[0].player_set, players[0].cards_in_set);
      }
      else if (choice == 3) { 
        // the player takes a pass
        printf("*You pass*\n");
      }
      else{
        printf("There is no option %d,my friend.\n",choice);
        goto CHOICE;
      }
      printf("Waiting for ai to make a move\n");
      int i = 1;
      // for (p_player = &players[1];p_player != &players[player_count-1];++p_player,i++) {
      // ^^ felt smart writing that 
      for (size_t i = 1; i < player_count ; i++){
        p_player = &players[i];
        int aiMv = ai_move(players[i],choice);
        printf("%i",aiMv);
        if  ( aiMv== 1) {
          give_up(set_sum(p_player->player_set),"The ai#",i);
        }
        else if (aiMv == 2) {
          stat = shuffle_deck(cards,p_player,1);
          if (stat  == 1)
            printf("The Ai takes a card\n");
          else{
            printf("Ai lost, coz its dumb af.");
            return 1;
          }
        }
        else if ( aiMv== 3) {
          printf("The AI passes.\n");
        }
        else {
          printf("Ai fail.\n");
          return 1;
        }
      }
    }
  }
  else {
    printf("Say yes when you are!\n");
    goto READY;
  }
  return 0;
}

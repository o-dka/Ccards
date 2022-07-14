#include <stdio.h>
#include <stdlib.h>
// configs
#include "deck_config.h"
// functions
// #include "rules/rules.h"
#include "ccard_ai/ccard_ai.h"
#include "types/types.h"
#include "general_logic/general_logic.h"

// int max(player_t *p,int plc){
  // int m = 0;
  // for (int i ; i < plc;i++,p++){
    // if (set_sum(p->player_set) > ){}
  // }
  // return m;
// }

int main() {
  int player_count,choice;
  char answer ;
  BRUH:
  printf("Input the amount of players :");
  if (scanf("%d",&player_count),player_count <= 1){
    printf("What are you doing.\n");
    goto BRUH;
  }
  printf("You will play with %d ai, as I am too lazy to implement local play.\n",player_count - 1);
  card_t cards[NUM];
  player_t players[player_count],*p_player = &players[0];
  fill_deck(cards);
  zero_pl(players,player_count);
  for (int i = 0 ; i < player_count ;i++,p_player++){
    shuffle_deck(cards,p_player,2); // randomise player sets
  }
  p_player = &players[0];
  READY:
  printf("Are you ready? (y/n) : ");
  scanf("%c",&answer) ;
  if (answer == 'y'){
    printf("First you make a move, then ai, you are  player #0.\nYou play the game until the sum of card values is greater than 21.\n");
    printf("Here are the cards you have been dealt: \n");
    print_cards(p_player->player_set, p_player->cards_in_set); //something is wrong here 
    for (int x = 1;;x++){
      printf("\n===============");
      printf("Round %d",x );
      printf("===============\n");
      CHOICE:
      printf("Will you:\n 1.Give up(show cards to other players).\n2.Take a card\n3.Pass\n : "),scanf("%d",&choice);
      switch (choice)
      {
      case 1: // the player shows cards;
      printf("Are you sure? (y/n) :\n"), scanf("%c",&answer);
        if (answer == 'y'){
          if (set_sum(players[0].player_set) > 21 ){
            printf("The player lost, his val is %d",set_sum(players[0].player_set));
          }
          else{
            give_up(set_sum(players[0].player_set),"The player#",0);
          }
        }
        else{
          goto CHOICE;
        }
        break;
      case 2: // the player takes a card;
        printf("*You take a card*\n");
        shuffle_deck(cards,p_player,1);
        print_cards(players[0].player_set, players[0].cards_in_set);
        break;
      case 3: // the player takes a pass
        printf("*You pass*\n");
        break;
      default:
        printf("There is no option %d,my friend.\n",choice);
        goto CHOICE;
        break;
      }
      printf("Waiting for ai to make a move\n");
      // for (p_player = &players[1];p_player != &players[player_count-1];p_player++) felt smart writing that 
      for (size_t i = 1; i < player_count ; i++){
        switch (ai_move(players[i],choice))
        {
        case 1:
          give_up(set_sum(players[i].player_set),"The ai#%i",(int)i);
          break;
        case 2 :
          printf("The Ai takes a card\n");
          break;
        case 3:
          printf("The AI passes.\n");
          break;  
        default:
          printf("Ai failiure\n");
          return 1;
          break;
        }
      }
    }
    printf("The winner is %d\n",0);
  }
  else {
    printf("Say yes when you are!\n");
    goto READY;
  }
  
  return 0;
}

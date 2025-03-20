/* (Assignment 3): Here is the overview of the implementation: To simulate the shuffled stack of cards, we use a pseudo random number generator that generates a random number in the range of 1 to 13. This represents the cards numbered 1 through 10, plus the jack, queen and king, respectively. If the card number is 1 to 10, it directly represents the value of the card. If the card number is 11 to 13, the card represents the jack, queen, and king, which all have the face value 10. */
/* Author: Edison Lin */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int draw_card() {
    return rand() % 13 + 1;
}

int main()
{
    srand(time(NULL));
    
    printf("************************************\n");
    printf("** Welcome to CENG 231 BlackJack! **\n");
    printf("************************************\n");
    int player_cards = draw_card();
    printf("Your first card is: %d\n", player_cards);

    if (player_cards == 1)
           {
                int ace_worth1;
                printf("This card is an Ace. Select whether you want it to be worth 1 or 11: ");
                scanf("%d", &ace_worth1);
                if ((ace_worth1 == 1))
                {
                        player_cards = 1;
                }
                if ((ace_worth1 == 11))
                {
                        player_cards = 11;
                }
           }
    if (player_cards >= 10)
	{
		player_cards = 10;
	}

    while (1)
    {
        int draw_another_card;
        printf("Do you want another card?\n");
        printf("Type 1 for Yes, 0 for No: ");
        scanf("%d", &draw_another_card);
        if (draw_another_card == 1) 
	{
	   int new_card = draw_card();
	   int player_score = player_cards + new_card;
	   printf("Your next card is: %d\n", new_card);
	   if (new_card == 1)
           {
                int ace_worth;
                printf("This card is an Ace. Select whether you want it to be worth 1 or 11: ");
                scanf("%d", &ace_worth);
                if ((ace_worth == 1))
                {
                        player_score = 1 + player_cards;
                }
		if ((ace_worth == 11))
		{
			player_score = 11 + player_cards;
		}
           }
	   if (new_card >= 10)
	   {
		player_score = 10 + player_cards;
	   }
	   player_cards = player_score;
           printf("Your combined value is: %d\n", player_score); 
           if (player_score > 21)
	   {
              printf("Sorry. You lose!\n");
              return 0;
           }
	   continue;
	   return 0;
        }
	if (draw_another_card == 0)
	{
		printf("Dealer draws another card.\n");
    		int dealer_cards = draw_card();
                printf("Dealers card is: %d\n", dealer_cards);
		printf("Dealers value is: %d, you have %d\n", dealer_cards, player_cards);

		while (dealer_cards < 17)
        	{
			int dealer_new_card = draw_card();
        		int dealer_total = dealer_cards + dealer_new_card;
			dealer_cards = dealer_total;
			printf("Dealer draws another card.\n");
			printf("Dealers card is: %d\n", dealer_new_card);
        		printf("Dealers value is: %d, you have %d\n", dealer_total, player_cards);
		}
		if (dealer_cards > 21)
                {
                	printf("Dealer loses. You win!\n");
                        break;
                } else if (dealer_cards == player_cards) {
                        printf("Dealer wins.\n");
                        break;
                } else if (dealer_cards > player_cards) {
                        printf("Dealer wins.\n");
                        break;
                } else {
          		printf("Dealer loses. You win!\n");
                        break;
		}
	 }
	return 0;
    }
    return 0;
    }


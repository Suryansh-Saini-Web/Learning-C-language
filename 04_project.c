// --------------------------------------Creating a Number Guessing Game.----------------------------------------------

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

int main(){
    char play = 'y';
    srand(time(0));
    while(play == 'y' || play == 'Y'){
        int rand_num = (rand() % 30) + 1;
        char buffer[100];
        int user_input;
        int chances = 4;
        int prev_guess[4];
        int guess_index = 0;
        while(chances){
            if(guess_index){
                printf("Previous guesses:");
                for(int i = 0; i < guess_index; i++){
                    printf(" %d", prev_guess[i]);
                }
                printf("\n");
            }
            printf("Chances left: %d \n", chances);
            printf("Please enter a number between 1 to 30: ");
            fgets(buffer, 100, stdin);
            if(sscanf(buffer,"%d%1s", &user_input) == 1 && user_input > 0 && user_input < 31){
                if(user_input > rand_num){
                    printf("Please enter a lower number.\n");
                    prev_guess[guess_index++] = user_input;
                    chances--;
                }else if(user_input < rand_num){
                    printf("Please enter a higher number.\n");
                    prev_guess[guess_index++] = user_input;
                    chances--;
                }else{
                    printf("You have won the game.\n");
                    break;
                }
            }else{
                printf("Please enter a valid input.\n");
            }   
        }
        if(!chances){
            printf("You have lost the game.\n");
            printf("Correct number was: %d \n", rand_num);
        }   
        printf("Do you want to play again(y/n) \n");
        scanf("%c", &play);
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }
    return 0;
}
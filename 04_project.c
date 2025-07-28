// --------------------------------------Creating a Number Guessing Game.----------------------------------------------

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    char replay = 'y';
    srand(time(0));
    while(replay == 'y' || replay == 'Y'){
        int rand_num = (rand() % 30) + 1;
        int input;
        char buffer[100];
        int chances = 4;
        int guesses[4];
        int guess_index = 0;
        while(chances){
            if(guess_index){
                printf("Previous Guesses: ");
                for(int i = 0; i < guess_index; i++){
                    printf("%d ", guesses[i] );
                }
                printf("\n");
            }
            printf("Chances left: %d\n", chances);
            printf("Please enter a number between 1 and 30: ");
            fgets(buffer, 100, stdin);
            if(sscanf(buffer, "%d", &input) == 1 && input >= 1 && input <= 30){
                guesses[guess_index++] = input;
                if(input > rand_num){
                    printf("You have entered a higher number.\n");
                    chances--;
                }else if(input < rand_num){
                    printf("You have entered a lower number.\n");
                    chances--;
                }else{
                    printf("You have won the Game.\n");
                    break;
                }
            }else{
                printf("Please enter a valid number.\n");
            }       
        }
        if(chances == 0){
            printf("You have lose the Game.\n");
            printf("Correct number was: %d\n", rand_num);
        }
        printf("Do you want to play again?(y/n)\n");
        scanf("%c", &replay);
        getchar();
    }
    return 0;
}
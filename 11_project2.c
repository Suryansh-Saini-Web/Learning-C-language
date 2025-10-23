// ------------------Make a Rock, Paper, Scissor game.-----------------

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void choice(int user, char player[10]){
    if(user == 1){
        printf("%s chose: Rock\n", player);
    }else if(user == 2){
        printf("%s chose: Paper\n", player);
    }else if(user == 3){
        printf("%s chose: Scissor\n", player);
    }
}

int main(){
    printf("Let's play Rock, Paper, Scissor game.\n");
    srand(time(0));
    char replay = 'y';
    while(replay == 'y' || replay == 'Y'){
        int comp = (rand() % 3) + 1;
        int user;
        char buffer[100];
        printf("Press 1 to choose Rock.\n");
        printf("Press 2 to choose Paper.\n");
        printf("Press 3 to choose Scissor.\n");
        fgets(buffer, 100, stdin);
        if(sscanf(buffer, "%d%1s", &user) == 1 && user <= 3 && user >= 1){
            choice(user, "You");
            choice(comp, "Computer");
            int result = (user - comp + 3) % 3;
            if(result == 0){
                printf("It's a draw.\n");
                continue;
            }else if(result == 2){
                printf("You lose.\n");
            }else if(result == 1){
                printf("You won.\n");
            }
        }else{
            printf("Please enter valid input.\n");
            continue;
        }
        printf("Do you want to play again(y/n): ");
        scanf("%c", &replay);
        int c;
        while((c = getchar()) != '\n' && c != EOF);
    }
    return 0;
}
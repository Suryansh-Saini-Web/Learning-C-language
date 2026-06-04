// ------------------Make a Rock, Paper, Scissor game.-----------------

#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void PrintChoice(int input){
    switch (input)
    {
    case 1:
        printf("Rock\n");
        break;
    case 2:
        printf("Paper\n");
        break;
    case 3:
        printf("Scissor\n");
        break;
    }
}

void ClearBuffer(){
    char ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int GetUserIntInput(int MaxInput, int MinInput){
    char buffer[3];
    while(1){
        printf("Enter Option: ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("Error: Invalid Input\n");
            continue;
        }
        char *end;
        int UserInput = strtol(buffer, &end, 10);
        if(end == buffer){
            printf("Error: Invalid Input\n");
            continue;
        }
        if(UserInput > MaxInput || UserInput < MinInput){
            printf("Error: Invalid Input\n");
            continue;
        }
        return UserInput;
    }
}

int GetComputerInput(){
    srand(time(NULL));
    return rand() % 3 + 1;
}

int GetResult(int UserInput, int ComputerInput){
    return (((ComputerInput - UserInput)+3) % 3);
}

int PlayAgain(){
    printf("Press '1' to Play Again\n");
    printf("Press '2' to Exit\n");
    int UserInput = GetUserIntInput(2,1);
    switch (UserInput)
    {
    case 1:
        return 1;
    case 2:
        return 0;
    }
}

int PlayGame(){
    printf("________________________________\n");
    printf("Press '1' to select 'ROCK'\n");
    printf("Press '2' to select 'PAPER'\n");
    printf("Press '3' to select 'SCISSOR'\n");
    printf("________________________________\n");
    int UserInput = GetUserIntInput(3, 1);
    int ComputerInput = GetComputerInput();
    printf("You Chose: ");
    PrintChoice(UserInput);
    printf("Computer Chose: ");
    PrintChoice(ComputerInput);
    int result = GetResult(UserInput, ComputerInput);
    switch (result)
    {
    case 0:
        printf("Result: It is a Draw\n");
        break;
    case 1:
        printf("Result: You Lose\n");
        break;
    case 2:
        printf("Result: You Won\n");
        break;
    }
    printf("________________________________\n");
    return PlayAgain();
}

int main(){
    printf("Let's Play Rock, Paper, Scissor Game\n");
    printf("Press '1' to Start Game\n");
    printf("Press '2' to Exit\n");
    int UserInput = GetUserIntInput(2,1);
    switch (UserInput)
    {
    case 1:;
        int play = 1;
        while(play){
            play = PlayGame();
        }
        break;
    case 2:
        return 0;
    }
    return 0;
}
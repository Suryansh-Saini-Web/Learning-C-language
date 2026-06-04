// --------------------------------------Creating a Number Guessing Game.----------------------------------------------

#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<string.h>

void ClearBuffer(){
    int ch;
    while((ch = getchar()) != '\n' && ch != EOF);
}

int GetUserIntInput/*Double Digit*/(int MaxInput, int MinInput){
    char buffer[4];
    while(1){
        printf("Enter Option: ");
        fgets(buffer, sizeof(buffer), stdin);
        if(strchr(buffer, '\n') == NULL){
            ClearBuffer();
            printf("Error: Invalid Input\n");
            continue;
        }
        char *end;
        int UserIntInput = strtol(buffer, &end, 10);
        if(end == buffer){
            printf("Error: Invalid Input\n");
            continue;
        }
        if(*end != '\n' && *end != '\0'){
            printf("Error: Invalid Input\n");
            continue;
        }
        if(UserIntInput > MaxInput || UserIntInput < MinInput){
            printf("Error: Invalid Input\n");
            continue;
        }
        return UserIntInput;
    }
}

int GenerateRandomNum(int MaxNum, int MinNum){
    srand(time(NULL));
    return rand() % MaxNum + MinNum;
}

void PrintPrevGuess(int arr[], int used){
    printf("Previous Guesses:");
    for(int i = 0; i < used; i++){
        printf(" %d", arr[i]);
        if(i == (used - 1)){
            continue;
        }else{
           printf(",", arr[i]); 
        }
    }
    printf("\n");
}

int PlayAgain(){
    printf("Press '1' to Play again\n");
    printf("Press '2' to exit\n");
    int UserInput = GetUserIntInput(2, 1);
    switch (UserInput)
    {
    case 1:
        return 1;
    case 2:
        return 0;
    }
}

int PlayGame(){
    int TotalChances = 5;
    int PrevGuess[4];
    int RandomNum = GenerateRandomNum(50, 1);
    printf("__________________________________________\n");
    printf("Successfully Generated Random Number\n");
    printf("Note: You get 5 Chances to Guess the Number\n");
    printf("__________________________________________\n");
    for(int i = 0; i < TotalChances; i++){
        if(i > 0){
            printf("Chances Used: %d\n", i);
            PrintPrevGuess(PrevGuess, i);
            printf("__________________________________________\n");
        }
        printf("Guess the Random Number (Range: 1 to 50)\n");
        int UserNum = GetUserIntInput(50, 1);
        printf("__________________________________________\n");
        if(UserNum == RandomNum){
            printf("You have Won the Game.\n");
            printf("__________________________________________\n");
            return PlayAgain();
        }
        if((i+1) == TotalChances){
            printf("You have Lost the Game.\n");
            printf("Random Number was: %d\n", RandomNum);
            printf("__________________________________________\n");
            return PlayAgain();
        }
        if(UserNum > RandomNum){
            PrevGuess[i] = UserNum;
            printf("You have entered a Higher Number.\n");
            continue;
        }
        if(UserNum < RandomNum){
            PrevGuess[i] = UserNum;
            printf("You have entered a Lower Number.\n");
            continue;
        }
    }
}

int main(){
    printf("NUMBER GUESSING GAME\n");
    printf("Press '1' to Start Game\n");
    printf("Press '2' to Exit\n");
    int UserInput = GetUserIntInput(2, 1);
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
        break;
    }
    return 0;
}
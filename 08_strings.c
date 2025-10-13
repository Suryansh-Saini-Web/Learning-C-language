// --------------Learning about strings.(uncomment the below code to execute)--------------------

/*
#include<stdio.h>

int main(){
    char string[] = "Suryansh";
    char *ptr = string;
    for(int i = 0; i < 8; i++){
        printf("Address of %d character of string: %u\n", i+1, ptr + i);
    }
    while(*ptr != '\0'){
        printf("%c", *ptr);
        ptr++;
    }
    return 0;
}
*/



// -------------Learning about printing string using %s data specifier.(uncomment the below code to execute)-----------------

/*
#include<stdio.h>

int main(){
    char *ptr = "Suryansh";
    printf("%s", ptr);
    return 0;
}
*/



// -------------Learning about taking string input from user.(uncomment the below code to execute)-----------------

/*
#include<stdio.h>

int main(){
    char name[20];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Your name is: %s", name);
    return 0;
}
*/



// -------------Learning about taking multi-word string input from user.(uncomment the below code to execute)-----------------

/*
#include<stdio.h>

int main(){
    char name[30];
    printf("Enter your full name: ");
    gets(name);
    printf("Your full name is: %s", name);
    return 0;
}
*/



// -------------Learning about strlen(), strcpy, strcat().(uncomment the below code to execute)-----------------

/*
#include<stdio.h>
#include<string.h>

int main(){
    char name[15];
    char surname[10];
    char pm[15];
    printf("Enter your first name: ");
    scanf("%s", name);
    printf("Enter your surname: ");
    scanf("%s", surname);
    strcat(name, " ");
    strcat(name, surname);
    printf("Your name has %d characters.\n", strlen(name));
    strcpy(pm, name);
    printf("India's PM name: %s", pm);
    return 0;
}
*/
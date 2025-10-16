// -----------------Learning about reading input from file and writing to file.(uncomment the below code to execute)-----------------

/*
#include<stdio.h>

void filecheck(FILE *ptr){
    if(ptr == NULL){
        printf("This file does not exist");
    }
}

int main(){
    FILE *ptr = fopen("10_sample.txt", "r");
    FILE *ptr2 = fopen("10_sample2.txt", "w");
    filecheck(ptr);
    int age;
    int age2;
    fscanf(ptr, "%d", &age);
    fscanf(ptr, "%d", &age2);
    fclose(ptr);
    printf("Suryansh is %d years old.\n", age);
    printf("Chirag is %d years old.\n", age2);
    fprintf(ptr2, "Suryansh is eighteen years old.\n");
    fprintf(ptr2, "Chirag is twelve years old.\n");
    fclose(ptr2);
    return 0;
}
*/



// -----------------Learning about reading characters from file and EOF.(uncomment the below code to execute)-----------------

/*
#include<stdio.h>

void filecheck(FILE *ptr){
    if(ptr == NULL){
        printf("This file does not exist");
    }
}

int main(){
    FILE *ptr = fopen("10_sample2.txt", "r");
    filecheck(ptr);
    char c;
    while((c = fgetc(ptr)) != EOF){
    printf("%c", c);
    }
    fclose(ptr);
    return 0;
}
*/
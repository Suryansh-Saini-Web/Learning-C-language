// ----------------Q1 - Write a program to read three integers from a file.(uncomment the below code to execute)-------------

/*
#include<stdio.h>

int main(){
    FILE *ptr = fopen("10_Sample.txt", "r");
    int age1, age2, age3;
    fscanf(ptr, "%d", &age1);
    fscanf(ptr, "%d", &age2);
    fscanf(ptr, "%d", &age3);
    fclose(ptr);
    printf("Suryansh's age is: %d\n", age1);
    printf("Chirag's age is: %d\n", age2);
    printf("Ritika's age is: %d", age3);
    return 0;
}
*/



// ----------------Q2 - Write a program to generate multiplication table of a given number in text format. Make sure that the file is readable and well formatted.(uncomment the below code to execute)-------------

/*
#include<stdio.h>

int main(){
    FILE *ptr = fopen("10_multi.txt", "w");
    int input;
    printf("Enter the number for which you want the multiplication table: ");
    scanf("%d", &input);
    for(int i = 1; i <= 10; i++){
        fprintf(ptr, "%d X %d = %d\n", input, i, input*i);
    }
    fclose(ptr);
    return 0;
}
*/



// ----------------Q3 - Write a program to read a text file character by character and write its content twice in a separate file.(uncomment the below code to execute)-------------

/*
#include<stdio.h>

void filecheck(FILE *ptr){
    if(ptr == NULL){
        printf("This file does not exist");
    }
}

int main(){
    FILE *ptr1 = fopen("10_sample2.txt", "r");
    filecheck(ptr1);
    FILE *ptr2 = fopen("10_twice.txt", "w");
    char c;
    for(int i = 0; i < 2; i++){
        while((c = fgetc(ptr1)) != EOF){
            fputc(c, ptr2);
        }
        rewind(ptr1);
    }
    fclose(ptr1);
    fclose(ptr2);
    return 0;
}
*/



// ----------------Q4 - Take name and salary of two employees as input from the user and write them to a text file.(uncomment the below code to execute)-------------

/*
#include<stdio.h>

struct employee{
    char name[30];
    int salary;
};

int main(){
    struct employee e1, e2;
    printf("Enter the name of the first employee: ");
    scanf("%s", e1.name);
    printf("Enter the salary of the first employee: ");
    scanf("%d", &e1.salary);
    printf("Enter the name of the second employee: ");
    scanf("%s", e2.name);
    printf("Enter the salary of the second employee: ");
    scanf("%d", &e2.salary);
    FILE *ptr = fopen("10_emp.txt", "w");
    fprintf(ptr, "Name of the first employee: %s\n", e1.name);
    fprintf(ptr, "Salary of the first employee: %d\n", e1.salary);
    fprintf(ptr, "Name of the second employee: %s\n", e2.name);
    fprintf(ptr, "Salary of the second employee: %d\n", e2.salary);
    fclose(ptr);
    return 0;
}
*/



// ----------------Q5 - Write a program to modify a file containing an integer to double its value.(uncomment the below code to execute)-------------

/*
#include<stdio.h>

void filecheck(FILE *ptr){
    if(ptr == NULL){
        printf("This file does not exist");
    }
}

int main(){
    FILE *ptr = fopen("10_sample3.txt", "r");
    filecheck(ptr);
    int number;
    fscanf(ptr, "%d", &number);
    fclose(ptr);
    number = number + number;
    ptr = fopen("10_sample3.txt", "w");
    fprintf(ptr, "%d", number);
    fclose(ptr);
    return 0;
}
*/

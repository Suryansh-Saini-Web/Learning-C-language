// ------------------Q1 - Create an array of 10 numbers. Verify using pointer arithmetic that (ptr + 2) points to the third element where ptr is a pointer pointing to the first element of the array.(uncomment the below code to execute)------------------

/*
#include<stdio.h>

int main(){
    int arr[10] = {0, 1, 4, 3, 4, 5, 6, 7, 8, 9};
    int *ptr = &arr[0];
    printf("Third element of array is: %d\n", arr[2]);
    printf("Third element of array is: %d", *(ptr + 2));
    return 0;
}
*/



// ------------------Q2 - Write a program to create an array of 10 integers and store multiplication table of 5 in it.(uncomment the below code to execute)------------------

/*
#include<stdio.h>

int main(){
    int table[10];
    for(int i = 0; i < 10; i++){
        table[i] = 5 * (i+1);
    }
    for(int i = 0; i < 10; i++){
        printf("5 X %d = %d\n", i+1, table[i]);
    }
    return 0;
}
*/



// ------------------Q3 - Repeat problem 3 for a general input provided by the user using scanf.(uncomment the below code to execute)------------------

/*
#include<stdio.h>

int main(){
    int number;
    int table[10];
    printf("Enter a number to get its multiplication table.\n");
    scanf("%d", &number);
    for(int i = 0; i < 10; i++){
        table[i] = number * (i + 1);
    }
    for(int i = 0; i < 10; i++){
        printf("%d X %d = %d\n", number, i+1, table[i]);
    }
    return 0;
}
*/



// ------------------Q4 - Write a program containing a function which reverses the array passed to it.(uncomment the below code to execute)------------------

/*
#include<stdio.h>

void reverse(int *ptr){
    printf("Entered numbers in reverse order: ");
    for(int i = 0; i < 10; i++){
        printf("%d", *(ptr - i));
        if(i < 9){
            printf(", ");
        }
    }
}

int main(){
    int arr[10];
    int *ptr = &arr[9];
    printf("Enter any 10 random numbers to reverse their order.\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    reverse(ptr);
    return 0;
}
*/



// ------------------Q5 - Write a program containing a function which counts the number of positive integers in an array.(uncomment the below code to execute)------------------

/*
#include<stdio.h>

void count(int *ptr){
    int positive = 0;
    for(int i = 0; i < 10; i++){
        if(*(ptr + i) > 0){
            positive++;
        }
    }
    printf("Total positive integers are: %d", positive);
}

int main(){
    int arr[10];
    int *ptr = &arr[0];
    printf("Enter any 10 random number.\n");
    for(int i = 0; i < 10; i++){
        scanf("%d", &arr[i]);
    }
    count(ptr);
    return 0;
}
*/



// ------------------Q6 - Create an array of size 3*10 containing multiplication tables of the numbers 2, 7, 9 respectively.(uncomment the below code to execute)------------------

/*
#include<stdio.h>

int main(){
    int table[3][10];
    int num[3] = {2, 7, 9};
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 10; j++){
            table[i][j] = num[i] * (j + 1);
        }
    }
    for(int i = 0; i < 3; i++){
       printf("Table of %d\n", num[i]);
        for(int j = 0; j < 10; j++){
            printf("%d X %d = %d\n", num[i], j+1, table[i][j]);
        }
    }
    return 0;
}
*/
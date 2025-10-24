// ------------Q1 - Write a program to dynamically create an array of size 6 capable of storing 6 integers.(Uncomment the below code to execute.)----------------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) malloc(6 * sizeof(int));
    for(int i = 0; i < 6; i++){
        printf("Enter the value of %d integer: ", i+1);
        scanf("%d", &ptr[i]);
    }
    for(int i = 0; i < 6; i++){
        printf("Value of %d integer: %d\n", i+1, ptr[i]);
    }
    return 0;
}
*/



// ------------Q2 - Solve problem 1 using calloc().(Uncomment the below code to execute.)----------------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) calloc(6, sizeof(int));
    for(int i = 0; i < 6; i++){
        printf("Value of %d integer: %d\n", i+1, ptr[i]);
    }
    return 0;
}
*/



// ------------Q3 - Create an array dynamically capable of storing 5 integers. Now use realloc so that it can now store 10 integers.(Uncomment the below code to execute.)----------------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) malloc(5 * sizeof(int));
    for(int i = 0; i < 5; i++){
        printf("Enter the value of %d integer: ", i+1);
        scanf("%d", &ptr[i]);
    }
    for(int i = 0; i < 5; i++){
        printf("Value of %d integer is: %d\n", i+1, ptr[i]);
    }
    ptr = realloc(ptr, 10 * sizeof(int));
    for(int i = 0; i < 5; i++){
        printf("Enter the value of %d integer: ", i+6);
        scanf("%d", &ptr[i+5]);
    }
    for(int i = 0; i < 10; i++){
        printf("Value of %d integer is: %d\n", i+1, ptr[i]);
    }
    return 0;
}
*/



// ------------Q4 - Create an array of multiplication table of 7 upto 10. Use realloc() to make it store 15 numbers.(Uncomment the below code to execute.)----------------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) malloc(10 * sizeof(int));
    for(int i = 0; i < 10; i++){
        ptr[i] = 7 * (i+1);
        printf("7 X %d = %d\n", i+1, ptr[i]);
    }
    ptr = realloc(ptr, 15 * sizeof(int));
    for(int i = 0; i < 5; i++){
        ptr[i+10] = 7 * (i+11);
        printf("7 X %d = %d\n", i+11, ptr[i+10]); 
    }
    return 0;
}
*/



// ------------Q5 - Attemp problem 3 using calloc().(Uncomment the below code to execute.)----------------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) calloc(5, sizeof(int));
    for(int i = 0; i < 5; i++){
        printf("Enter the value of %d integer: ", i+1);
        scanf("%d", &ptr[i]);
    }
    for(int i = 0; i < 5; i++){
        printf("Value of %d integer is: %d\n", i+1, ptr[i]);
    }
    ptr = realloc(ptr, 10 * sizeof(int));
    for(int i = 0; i < 5; i++){
        printf("Enter the value of %d integer: ", i+6);
        scanf("%d", &ptr[i+5]);
    }
    for(int i = 0; i < 10; i++){
        printf("Value of %d integer is: %d\n", i+1, ptr[i]);
    }
    return 0;
}
*/
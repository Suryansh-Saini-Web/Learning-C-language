//-----------Q1- Write a program to print the address of a variable. Use this address to get the value of this variable.(uncomment the below code to execute)-----------

/*
#include<stdio.h>

int main(){
    int a = 1;
    printf("Address of variable a is %u\n", &a);
    printf("Value of variable a retrieved from its address: %d", *(&a));
    return 0;
}
*/



// -----------------Q2- Write a program having a variable "i". Print the address of "i". Pass this variable to a function and print its address. Are these addresses same? Why?(uncomment the code below to execute)-----------------------

/*
#include<stdio.h>

void pass(int i);

int main(){
    int i;
    printf("Address of variable i is: %u\n", &i);
    pass(i);
    return 0;
}

void pass(int i){
    printf("Address of variable i is: %u\n", &i);
    // The address of both "i" is different because the function recieves a copy of variable i and not the actual variable i.
}
*/



//  -----------------Q3- Write a program to change the value of a variable to ten times of its current value. Write a function and pass the value by reference.(uncomment the code below to execute)-----------------------

/*
#include<stdio.h>

void change(int *a);
int main(){
    int a = 1;
    change(&a);
    printf("Value of a is: %d\n", a);
    return 0;
}

void change(int *a){
    *a = *a * 10;
}
*/



//  -----------------Q4- Write a program using a function which calculates the sum and average of two numbers. Use pointers and print the values of Sum and Average in main().(uncomment the code below to execute)-----------------------

/*
#include<stdio.h>

int sum(int *a, int *b);

float average(int *a, int *b);

int main(){
    int a = 5, b = 6;
    printf("Sum of a and b is: %d\n", sum(&a, &b));
    printf("Average of a and b is: %.2f", average(&a, &b));
    return 0;
}

int sum(int *a, int *b){
    return *a + *b;
}

float average(int *a, int *b){
    return (*a + *b)/2.0;
}
*/



//  -----------------Q5- Write a program to print the value of a variable "i" by using "pointer to pointer" type of variable.(uncomment the code below to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int i = 1;
    int *a = &i;
    int **b = &a;
    printf("Value of i is: %d", *(*b));
    return 0;
}
*/



//  -----------------Q6- Try problem 3 using call by value and verify that it does not change the value of the said variable.(uncomment the code below to execute)-----------------------

/*
#include<stdio.h>

void change(int a);

int main(){
    int a = 1;
    change(a);
    printf("Value of a is: %d\n", a);
    return 0;
}

void change(int a){
    a = a * 10;
}
*/
// ------------Q1 - Write a program to print multiplication table of a given number n.(Uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int n;
    int i = 1;
    printf("Enter a number to display its multiplication table: ");
    scanf("%d", &n);
    while(i <= 10){
        printf("%d X %d = %d \n", n, i, n * i);
        i++;
    }
    return 0;
}
*/



// ------------Q2 - Write a program to print multiplication table of a 10 in reversed order.(Uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    for(int i = 10; i; i--){
        printf("10 X %d = %d \n", i, 10 * i);
    }
    return 0;
}
*/



// ------------Q3 - Write a program to sum first ten natural numbers using while loop.(Uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int i = 1, sum = 0;
    while(i <= 10){
        sum += i;
        i++;
    }
    printf("Sum of first ten natural numbers: %d", sum);
    return 0;
}
*/



// ------------Q4 - Write a program to sum first ten natural numbers using do-while loop.(Uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int i = 1, sum = 0;
    do{
        sum += i;
        i++;
    }while(i <= 10);
    printf("Sum of first ten natural numbers: %d", sum);
    return 0;
}
*/



// ------------Q5 - Write a program to sum first ten natural numbers using for-loop.(Uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int sum = 0;
    for(int i = 1; i <= 10; i++){
        sum += i;
    }
    printf("Sum of first ten natural numbers: %d", sum);
    return 0;
}
*/



// ------------Q6 - Write a program to calculate the sum of the numbers occuring in the multiplication table of 8.(Uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int sum = 0;
    for(int i = 1; i <= 10; i++){
        int multiply = 8 * i;
        sum += multiply;
    }
    printf("Sum of numbers occuring in the multiplication table of 8: %d", sum);
    return 0;
}
*/




// ------------Q7 - Write a program to calculate the factorial of a given number using a for-loop.(Uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int input, sum = 1;
    printf("Please enter a number to find its factorial. \n");
    scanf("%d", &input);
    int original = input;
    for(int a = input; a; a--){
        sum *= a;
    }
    printf("Factorial of %d is: %d", input, sum);
    return 0;
}
*/



// ------------Q8 - Write a program to calculate the factorial of a given number using a while loop.(Uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int input, sum = 1;
    printf("Please enter a number to find its factorial \n");
    scanf("%d", &input);
    int original = input;
    while(input){
        sum *= input;
        input--;
    }
    printf("Factorial of %d is: %d", original, sum);
    return 0;
}
*/
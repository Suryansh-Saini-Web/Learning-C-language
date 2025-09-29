// -------------Q1 - Write a program using functions to find average of three numbers.-----------------

// Below Code is written by me according to my knowledge, but it contains a bug. Check the comment on line 20 in the code below for bug.(uncomment below code to execute)


/*
#include<stdio.h>

float average(int a, int b, int c);

int main(){
    int a, b, c;
    printf("Enter three numbers to find their average: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Average is: %.2f\n", average(a, b, c));
    return 0;
}

float average(int a, int b, int c){
    return (a + b + c)/3; // here the function gives wrong answer because a, b, c and 3 both are int data type and int data type divided by int data type gives an int value. Even though the function is returning a float value but it actually converts the int answer to float and therefore gives the wrong average. 
}
*/


// Below Code is written after discussing with ChatGPT about the reason for bug. Check the comment on line 42 in the code below for bug's answer.(uncomment below code to execute)


/*
#include<stdio.h>

float average(int a, int b, int c);

int main(){
    int a, b, c;
    printf("Enter three numbers to find their average: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("Average is: %.2f\n", average(a, b, c));
    return 0;
}

float average(int a, int b, int c){
    return (a + b + c)/3.0; // here we converted int 3 to float 3 by adding a decimal point. Due to this now a, b, c (int data type) is divided by float 3.0 and an int data type divided by float data type gives float value. So the function directly returns a float value instead of converting int average to float data type, and therefore we get the correct answer.
}
*/



// -------------Q2 - Write a function to convert Celsius temperature into Fahrenheit.(uncomment below code to execute)-----------------

/*
#include<stdio.h>

float fahrenheit(float celsius);

int main(){
    float celsius;
    printf("Please enter temperature (in Celsius) to get temperature in Fahrenheit.\n");
    scanf("%f", &celsius);
    printf("Temperature in Fahrenheit: %.2f\n", fahrenheit(celsius));
    return 0;
}

float fahrenheit(float celsius){
    return (celsius * 9.0/5.0) + 32;
}
*/



// ------------Q3 - Write a function to calculate force of attraction on a body, exerted by earth.(uncomment below code to execute)--------------

/*
#include<stdio.h>

float force(int mass);

int main(){
    int mass;
    printf("Please enter the mass of the body (in kg): ");
    scanf("%d", &mass);
    printf("Force exerted: %.1f N", force(mass));
    return 0;
}

float force(int mass){
    return 9.8 * mass;
}
*/



// ------------Q4 - Calculate nth element of Fibonacci series using recursion.(uncomment below code to execute)--------------

/*
#include<stdio.h>

int fibonacci(int number);

int main(){
    int number;
    printf("Enter a number to calculate the nth Fibonacci number: ");
    scanf("%d", &number);
    printf("%dth element of Fibonacci series is: %d", number, fibonacci(number));
    return 0;
}

int fibonacci(int number){
    if(number == 0){
        return 0;
    }else if(number == 1){
        return 1;
    }else{
        return fibonacci(number - 1) + fibonacci(number - 2);
    }
}
*/



// ------------Q5 - Calculate nth element of Fibonacci series using iterative approach.(uncomment below code to execute)--------------

/*
#include<stdio.h>

int fibonacci(int number);

int main(){
    int number;
    printf("Enter a number to find the nth element of Fibonacci series.\n");
    scanf("%d", &number);
    printf("%dth element of Fibonacci series is: %d", number, fibonacci(number));
}

int fibonacci(int number){
    if(number == 0 || number == 1){
        return number;
    }else{
        int a = 0, b = 1, c;
        for(int i = 1; i < number; i++){
            c = a + b;
            a = b;
            b = c;
        }
        return c;
    }
}
*/



// ------------Q6 - Write a recursive function to calculate the sum of first n natural numbers.(uncomment to execute)--------------

/*
#include<stdio.h>

int sum(int number);

int main(){
    int number;
    printf("Enter a number to find the sum of first n natural numbers: ");
    scanf("%d", &number);
    printf("Sum of first n natural numbers is: %d", sum(number));
    return 0;
}

int sum(int number){
    if(number == 0){
        return 0;
    } else if(number == 1){
        return 1;
    } else{
        return number + sum(number - 1);
    }
}
*/



// ------------Q7 - Write a program using function to print the star pattern.(uncomment to execute)--------------

/*
#include<stdio.h>

void pattern(int lines);

int main(){
    int lines;
    printf("Enter how many lines of start pattern you want: ");
    scanf("%d", &lines);
    if(lines == 0){
        printf("Please enter a number above 0.");
    }else{
        pattern(lines);
    }
    return 0;
}

void pattern(int lines){
    if(lines == 1){
        printf("*\n");
    }else{
        pattern(lines - 1);
        int loop = (2 * lines - 1);
        for(int i = 0; i < loop ; i++){
            printf("*");
        }
        printf("\n");
    }
}
*/



// ------------Q8 - Write a program using for loop to print the star pattern.(uncomment to execute)--------------

/*
#include<stdio.h>

void pattern(int lines);

int main(){
    int lines;
    printf("Enter how many lines of star pattern you want: ");
    scanf("%d", &lines);
    pattern(lines);
    return 0;
}

void pattern(int lines){
    for(int i = 1; i <= lines; i++){
        for(int j = 0; j < (2 * i - 1); j++){
            printf("*");
        }
        printf("\n");
    }
}
*/
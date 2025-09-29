// ------------Learning about functions - function prototype, function calling and function definition.---------------------

//--------------------Uncomment below code to execute.------------------

/*
#include<stdio.h>

void display();

int main(){
    display();
    return 0;
}

void display(){
    printf("Hello World.\n");
}
*/



//--------------------Uncomment below code to execute.------------------

/*
#include<stdio.h>

void good_morning();
void good_afternoon();
void good_night();

int main(){
    good_morning();
    return 0;
}

void good_morning(){
    printf("Good Morning.\n");
    good_afternoon();
}

void good_afternoon(){
    printf("Good Afternoon.\n");
    good_night();
}

void good_night(){
    printf("Good Night.\n");
}
*/



//--------------------Uncomment below code to execute.------------------

/*
#include<stdio.h>

int sum(int a, int b);

int main(){
    int a, b;
    printf("Enter two numbers to find their sum.\n");
    scanf("%d %d", &a, &b);
    printf("%d\n", sum(a, b));
    return 0;
}

int sum(int a, int b){
    return a+b;
}
*/



//--------------------Uncomment below code to execute.------------------

/*
#include<stdio.h>

int area(int side);

int main(){
    int side;
    printf("Please enter the side of square to find its area: ");
    scanf("%d", &side);
    printf("%d\n", area(side));
    return 0;
}

int area(int side){
    return side*side;
}
*/



// ----------------------Learning about Recursion.----------------

#include<stdio.h>

int factorial(int number);

int main(){
    int number;
    printf("Enter a number to find its factorial: ");
    scanf("%d", &number);
    printf("Factorial is: %d\n", factorial(number));
    return 0;
}

int factorial(int number){
    if(number == 0 || number == 1){
        return 1;
    }else{
        return factorial(number - 1) * number;
    }
}
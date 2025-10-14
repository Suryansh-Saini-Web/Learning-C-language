// --------------------Q1 -  Create a two dimensional vector using structures.(Uncomment the below code to execute)---------------

/*
#include<stdio.h>

struct vector{
    float x;
    float y;
};

int main(){
    struct vector v1 = {25.2, 15.6};
    printf("Value of x: %.2f\n", v1.x);
    printf("Value of y: %.2f", v1.y);
    return 0;
}
*/



// --------------------Q2 -  Write a function SumVector which returns the sum of two vectors passed to it. The vectors must be two-dimensional.(Uncomment the below code to execute)---------------

/*
#include<stdio.h>

struct vector{
    float x;
    float y;
};

struct vector sumVector(struct vector v1, struct vector v2){
    struct vector result;
    result.x = v1.x + v2.x;
    result.y = v1.y + v2.y;
    return result;
}

int main(){
    struct vector v1, v2, result;
    printf("Enter the value of x of vector v1: ");
    scanf("%f", &v1.x);
    printf("Enter the value of y of vector v1: ");
    scanf("%f", &v1.y);
    printf("Enter the value of x of vector v2: ");
    scanf("%f", &v2.x);
    printf("Enter the value of y of vector v2: ");
    scanf("%f", &v2.y);
    result = sumVector(v1, v2);
    printf("Sum of vectors: x = %.2f, y = %.2f", result.x, result.y);
    return 0;
}
*/



// --------------------Q3 - Write a program to illustrate the use of arrow operator.(Uncomment the below code to execute)---------------

/*
#include<stdio.h>

struct student{
    int class;
};

int main(){
    struct student suryansh;
    struct student *ptr = &suryansh;
    ptr->class = 12;
    printf("Suryansh is in class %d", ptr->class);
    return 0;
}
*/



// --------------------Q4 - Create an array of 5 complex numbers using structures and display them with a display function. Take input from user.(Uncomment the below code to execute)---------------

/*
#include<stdio.h>

struct complex{
    int real;
    int imaginary;
};

void display(struct complex number){
    printf("Value of real number: %d\n", number.real);
    printf("Value of imaginary number: %d\n", number.imaginary);
}

int main(){
    struct complex number[5];
    for(int i = 0; i < 5; i++){
        printf("Enter the %d real number: ", i+1);
        scanf("%d", &number[i].real);
        printf("Enter the %d imaginary number: ", i+1);
        scanf("%d", &number[i].imaginary);
    }
    for(int i = 0; i < 5; i++){
        display(number[i]);
    }
    return 0;
}
*/



// --------------------Q5 - Write problem 4's structure using typedef keyword.(Uncomment the below code to execute)---------------

/*
#include<stdio.h>

typedef struct complex{
    int real;
    int imaginary;
}number;

void display(number n1){
    printf("Value of real number is: %d\n", n1.real);
    printf("Value of imaginary number is: %d\n", n1.imaginary);
}

int main(){
    number n1[5];
    for(int i = 0; i < 5; i++){
        printf("Enter the value of %d real number: ", i+1);
        scanf("%d", &n1[i].real);
        printf("Enter the value of %d imaginary number: ", i+1);
        scanf("%d", &n1[i].imaginary);
    }
    for(int i = 0; i < 5; i++){
        display(n1[i]);
    }
    return 0;
}
*/



// --------------------Q6 - Create a structure representing a bank account of a customer.(Uncomment the below code to execute)---------------

/*
#include<stdio.h>

typedef struct bankAccount{
    int accountNo;
    int cin;
    char branch[15];
    float balance;
}bA;

int main(){
    bA suryansh = {1097583, 9807564, "Delhi", 120965.67};
    printf("Account No. of Suryansh is: %d\n", suryansh.accountNo);
    printf("CIN of Suryansh is: %d\n", suryansh.cin);
    printf("Branch of Suryansh is: %s\n", suryansh.branch);
    printf("Account balance of Suryansh is: %.2f\n", suryansh.balance);
    return 0;
}
*/



// --------------------Q7 - Write a structure capable of storing date. Write a function to compare those dates.(Uncomment the below code to execute)---------------

/*
#include<stdio.h>

struct date{
    int date;
    int month;
    int year;
};

void display(struct date d1){
    printf("Date is: %d/%d/%d\n", d1.date, d1.month, d1.year);
}

int comp(struct date d1, struct date d2){
    if(d1.year < d2.year){
        printf("Date d2 is greater than d1: Yes");
    }else if(d1.year > d2.year){
        printf("Date d2 is greater than d1: No");
    }else if(d1.year == d2.year){
        if(d1.month < d2.month){
            printf("Date d2 is greater than d1: Yes");
        }else if(d1.month > d2.month){
            printf("Date d2 is greater than d1: No");
        }else if(d1.month == d2.month){
            if(d1.date < d2.date){
                printf("Date d2 is greater than d1: Yes");
            }else{
                printf("Date d2 is greater than d1: No");
            }
        }
    }
}

int main(){
    struct date d1 = {15, 9, 25};
    struct date d2 = {14, 10, 25};
    display(d1);
    display(d2);
    comp(d1, d2);
    return 0;
}
*/



// --------------------Q8 - Write a structure capable of storing time. Write a function to compare those dates.(Uncomment the below code to execute)---------------

/*
#include<stdio.h>

struct time{
    int hours;
    int minutes;   
};

void display(struct time t){
    printf("Time: %d:%d\n", t.hours, t.minutes);
}

int comp(struct time t1, struct time t2){
    if(t1.hours < t2.hours){
        printf("Time t2 is greater than time t1: Yes");
    }else if(t1.hours > t2.hours){
        printf("Time t2 is greater than time t1: No");
    }else if(t1.hours == t2.hours){
        if(t1.minutes < t2.minutes){
            printf("Time t2 is greater than time t1: Yes");
        }else{
            printf("Time t2 is greater than time t1: No");
        }
    }
}

int main(){
    struct time t1, t2;
    printf("Enter the time T1 hour: ");
    scanf("%d", &t1.hours);
    printf("Enter the time T1 minutes: ");
    scanf("%d", &t1.minutes);
    printf("Enter the time T2 hour: ");
    scanf("%d", &t2.hours);
    printf("Enter the time T2 minutes: ");
    scanf("%d", &t2.minutes);
    display(t1);
    display(t2);
    comp(t1, t2);
    return 0;
}
*/
//--------------- Practice Question 1 - Program to find whether a student is pass or fail, if it requires total 40% and at least 33% in each subject to pass. Assume 3 subjects and take marks as an input from user.---------------- (uncomment the below code to execute.)

/*
#include <stdio.h>

int main()
{
    int maths, physics, chemistry;
    printf("Please enter Maths marks\n");
    scanf("%d", &maths);
    printf("Please enter Physics marks\n");
    scanf("%d", &physics);
    printf("Please enter Chemistry marks\n");
    scanf("%d", &chemistry);
    float total_percentage = (maths + physics + chemistry) / 3;
    if (maths >= 33 && physics >= 33 && chemistry >= 33 && total_percentage >= 40)
    {
        printf("You have passed the exam.\n");
    }
    else
    {
        printf("You have failed the exam.\n");
    }
    return 0;
}
*/



// --------------- Practice Question 2 - Program to calculate Income Tax according to these income slabs: Below 2.5 lakh - 0 tax, 2.5 lakh to 5 lakh - 5% tax, 5 lakh to 10 lakh - 20% tax, Above 10 lakh - 30% tax.------------------------- (uncomment the below code to execute.)

// --------This is the code written by me as per my understanding.------------

/*
#include <stdio.h>

int main()
{
    int income;
    printf("Please enter your income.\n");
    scanf("%d", &income);
    if (income <= 250000)
    {
        printf("You have to pay 0 income tax\n");
    }
    else if (income <= 500000 && income > 250000)
    {
        printf("You have to pay %d income tax\n", (income - 250000) * 5 / 100);
    }
    else if (income <= 1000000 && income > 500000)
    {
        printf("You have to pay %d income tax\n", (income - 500000) * 20 / 100 + 12500);
    }
    else if (income > 1000000)
    {
        printf("You have to pay %d income tax\n", (income - 1000000) * 30 / 100 + 12500 + 100000);
    };
    return 0;
}
*/



// --------------This is the code I had written after getting feedback from ChatGPT, because the above code is not scalable.----------------------

/*
#include<stdio.h>

int main(){
    float income, tax = 0;
    printf("Please enter your Income: ");
    scanf("%f", &income);
    if(income > 1000000){
        tax += (income - 1000000) * 30 / 100;
        income = 1000000;
    }
    if (income > 500000){
        tax += (income - 500000) * 20 / 100;
        income = 500000; 
    }
    if (income > 250000){
        tax += (income - 250000) * 5 / 100;
        income = 250000; 
    }
    printf("You have to pay %.2f tax.\n", tax);
    return 0;
}
*/



// --------------- Practice Question 3 - Program to find whether year entered by user is leap year or not.(uncomment the below code to execute)--------------------

/*
#include<stdio.h>

int main(){
    int year;
    printf("Please enter the year.\n");
    scanf("%d", &year);
    if(year % 4 == 0 && year % 100 != 0 || year % 400 == 0){
        printf("This is a leap year.\n");
    } else {
        printf("This is not a leap year.\n");
    }
    return 0;
}
*/



// ------------------ Practice Question 4 - Program to find whether a character entered by user is Lowercase or Uppercase.(uncomment the below code to execute)------------------

/*
#include <stdio.h>

int main()
{
    char character;
    printf("Please enter a character: ");
    scanf("%c", &character);
    if (character >= 'A' && character <= 'Z')
    {
        printf("It is a Uppercase alphabet.\n");
    }
    else if (character >= 'a' && character <= 'z')
    {
        printf("It is a Lowercase alphabet.\n");
    }
    else
    {
        printf("Please enter a alphabet.\n");
    }
    return 0;
}

*/



// ------------- Practice Question 5 - Program to find greatest of the four numbers entered by user.(uncomment the below code to execute)----------------

// --------This is the code written by me as per my understanding.------------

/*
#include<stdio.h>

int main(){
    int first, second, third, fourth;
    printf("Please enter any four numbers to find the greatest. \n");
    scanf("%d" "%d" "%d" "%d", &first, &second, &third, &fourth);
    if(first > second && first > third && first > fourth){
        printf("%d is greatest of the four.\n", first);
    }else if(second > first && second > third && second > fourth){
        printf("%d is greatest of the four.\n", second);
    } else if(third > first && third > second && third > fourth){
       printf("%d is greatest of the four.\n", third); 
    }else{
        printf("%d is greatest of the four.\n", fourth);
    }
    return 0;
}
*/



// --------------This is the code I had written after getting feedback from ChatGPT, because the above code is not clean.----------------------

/*
#include<stdio.h>

int main(){
    int first, second, third, fourth;
    printf("Please enter any four number to find the greatest.\n");
    scanf("%d" "%d" "%d" "%d", &first, &second, &third, &fourth);
    int greatest = first;
    if (second > greatest){
        greatest = second;
    }
    if (third > greatest){
        greatest = third;
    }
    if (fourth > greatest){
        greatest = fourth;
    }
    printf("%d is the greatest of four.\n", greatest);
    return 0;
}
*/
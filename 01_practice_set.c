// --------Practice question 1 - Calculate area of rectangle using hard coded inputs----------- (uncomment to execute)
/*
#include<stdio.h>

int main(){
    int length = 37;
    int breadth = 45;
    printf("The area of rectangle is %d", length * breadth);
    return 0;
}
*/

// --------Practice question 2 - Calculate area of rectangle using inputs supplied by user----------- (uncomment to execute)

/*
#include<stdio.h>

int main(){
    float length, breadth;
    printf("Please enter the length of rectangle in cm \n");
    scanf("%f", &length);
    printf("Please enter the breadth of rectangle in cm \n");
    scanf("%f", &breadth);
    printf("Area of rectangle is %.2f cm square", length * breadth);
    return 0;
}
*/

// --------Practice question 3 - Calculate area of circle and volume of cylinder (height of cylinder already given) using inputs supplied by user----------- (uncomment to execute)

/*
#include<stdio.h>

int main(){
    float radius;
    printf("Please enter the radius of circle in cm \n");
    scanf("%f", &radius);
    float area = 3.14 * radius * radius;
    int height = 10;
    float volume = area * height;
    printf("Area of circle is %.2f cm square \n", area);
    printf("Volume of cylinder is %.2f cm cube", volume);
    return 0;
}
*/


// --------Practice question 4 - Convert Centigrade temperature to Fahrenheit using inputs supplied by user----------- (uncomment to execute)

/*
#include<stdio.h>
 
int main(){
    float celsius;
    printf("Please enter the temp. in Celsius \n");
    scanf("%f", &celsius);
    float fahrenheit = (celsius * 9 / 5) + 32;
    printf("Temp. in Fahrenheit - %.2f", fahrenheit);
    return 0;
}
*/


// --------Practice question 5 - Calculate Simple interest using inputs supplied by user----------- (uncomment to execute)

/*
#include<stdio.h>

int main(){
    float principal, interest_rate, time;
    printf("Please enter the Principal amount \n");
    scanf("%f", &principal);
    printf("Please enter the Rate of Interest \n");
    scanf("%f", &interest_rate);
    printf("Please enter the time period \n");
    scanf("%f", &time);
    float simple_interest = (principal * interest_rate * time) / 100;
    printf("Simple Interest = %.2f", simple_interest);
    return 0;
}
*/
// ---------------Learning about pointers, "%u" format specifier and (*) value at operator.(uncomment the below code to execute)---------------------------

/*
#include<stdio.h>

int main(){
    int a = 32;
    int *b = &a;
    printf("Value of a: %d\n", a);
    printf("Value of a: %d\n", *b);
    printf("Value of a: %d\n", *(&a));
    printf("Value of b: %d\n", b);
    printf("Address of a: %u\n", &a);
    printf("Address of a: %u\n", b);
    printf("Address of b: %u\n", &b);
    return 0;
}
*/



// ---------------------Learning about swapping numbers using call by reference function.(uncomment the below code to execute)------------------

/*
#include<stdio.h>

void swap(int *a, int *b);

int main(){
    int a = 3, b = 4;
    printf("Value of a and b before swap is %d and %d\n", a, b);
    swap(&a, &b);
    printf("Value of a and b after swap is %d and %d", a, b);
    return 0;
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
*/
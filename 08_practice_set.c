// --------------Q1 - Write a program to take string as an input from the user using %s.(Uncomment the below code to execute)-------------------

/*
#include<stdio.h>

int main(){
    char input[15];
    printf("Enter your first name: ");
    scanf("%s", input);
    printf("Your first name is: %s", input);
    return 0;
}
*/



// --------------Q2 - Write your own version of strlen().(Uncomment the below code to execute)-------------------

/*
#include<stdio.h>

int main(){
    char name[30];
    char *ptr = name;
    int length = 0;
    printf("Enter your full name: ");
    gets(name);
    while(*ptr != '\0'){
        length++;
        ptr++;
    }
    printf("There are %d characters in your full name.", length);
    return 0;
}
*/



// ---------------------Q3 - Write a function slice() to slice a string. It should change the original string such that it is now the sliced string. Take m and n as the start and ending position for slice.(Uncomment the below code to execute)----------------------------

/*
#include<stdio.h>

void slice(char *ptr, int m, int n){
    int i = 0;
    int original = n;
    while(n-m){
        *(ptr + i) = *(ptr + m + i);
        i++;
        n--;
    }
    *(ptr + (original-m)) = '\0';
}

int main(){
    char str[30];
    char *ptr = str;
    int m, n;
    printf("Enter your name to slice it: ");
    gets(str);
    printf("Enter the starting position of slice: ");
    scanf("%d", &m);
    printf("Enter the ending position of slice: ");
    scanf("%d", &n);
    slice(ptr, m, n);
    printf("Sliced string: %s\n", str);
    return 0;
}
*/



// ---------------------Q4 - Write your own version of strcpy().(Uncomment the below code to execute)----------------------------

/*
#include<stdio.h>

void strcopy(char *ptr2, char *ptr1){
    while(*ptr1 != '\0'){
        *ptr2 = *ptr1;
        ptr1++;
        ptr2++;
    }
    *ptr2 = '\0';
}

int main(){
    char src[30];
    char tgt[30];
    char *ptr1 = src;
    char *ptr2 = tgt;
    printf("Enter your full name: ");
    gets(src);
    strcopy(ptr2, ptr1);
    printf("Your Full name is: %s", tgt);
    return 0;
}
*/



// ---------------------Q5 - Write a program to encrypt and decrypt a string by adding 1 to the ascii value of its characters.(Uncomment the below code to execute)----------------------------

/*
#include<stdio.h>

void encrypt(char *ptr){
    while(*ptr != '\0'){
        *ptr += 1;
        ptr++; 
    }
}

void decrypt(char *ptr){
    while(*ptr != '\0'){
        *ptr -= 1;
        ptr++; 
    }
}

int main(){
    char city[30];
    char *ptr = city;
    printf("Enter your city name: ");
    gets(city);
    encrypt(ptr);
    printf("Encrypted message: %s\n", city);
    decrypt(ptr);
    printf("Decrypted message: %s", city);
    return 0;
}
*/
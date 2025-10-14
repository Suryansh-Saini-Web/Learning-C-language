// -------------------Learning about structures.(Uncomment to execute)-----------------------

/*
#include<stdio.h>
#include<string.h>

struct student{
    char full_name[30];
    int class;
    char section;
    int roll_no;
};

int main(){
    struct student s1;
    strcpy(s1.full_name, "Suryansh Saini");
    s1.class = 12;
    s1.section = 'F';
    s1.roll_no = 12541;
    printf("%s", s1.full_name);
    return 0;
}
*/



// --------------Learning about Array of Structures.(Uncomment to execute)--------------

/*
#include<stdio.h>
#include<string.h>

struct student{
    char name[30];
    int class;
    char section;
    int roll_no;
};

int main(){
    struct student ukg[30];
    strcpy(ukg[0].name, "Chirag");
    ukg[0].class = 1;
    ukg[0].section = 'A';
    ukg[0].roll_no = 01;
    return 0;
}
*/



// --------------Learning about initializing structure.(Uncomment to execute)--------------

/*
#include<stdio.h>

struct student{
    int class;
    int roll_no;
};

int main(){
    struct student chirag = {8, 11};
    printf("Chirag's class is: %d\n", chirag.class);
    printf("Chirag's roll no. is: %d\n", chirag.roll_no);
    return 0;
}
*/



// --------------Learning about "pointer" to structure.(Uncomment to execute)--------------

/*
#include<stdio.h>
#include<string.h>

struct student{
    char name[15];
};

int main(){
    struct student one;
    struct student *ptr; 
    ptr = &one;
    strcpy((*ptr).name, "Chirag");
    printf("%s", one.name);
    return 0;
}
*/



// --------------Learning about arrow operator.(Uncomment to execute)--------------

/*
#include<stdio.h>

struct student{
    int class;
};

int main(){
    struct student suryansh;
    struct student *ptr = &suryansh;
    ptr->class = 12;
    printf("Suryansh is in %d class", ptr->class);
    return 0;
}
*/



// --------------Learning about how to pass structure to a function.(Uncomment to execute)--------------

/*
#include<stdio.h>

struct student{
    int class;
};

void show(struct student n){
    printf("Suryansh is in class %d", n.class);
}

int main(){
    struct student suryansh = {12};
    show(suryansh);
    return 0;
}
*/



// --------------Learning about typedef.(Uncomment to execute)--------------

/*
#include<stdio.h>

typedef struct student{
    int class;
}student;

void initialize(student *ptr){
    ptr->class = 12;
}

int main(){
    student suryansh;
    student *ptr = &suryansh;
    initialize(ptr);
    printf("Suryansh is in class %d", suryansh.class);
    return 0;
}
*/
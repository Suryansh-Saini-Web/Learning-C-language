// ----------Learning about while loop and increment (++) operator. (uncomment below code to execute)--------------

/*
#include<stdio.h>

int main(){
    int i = 0;
    while(i <= 10){
        printf("Value of i is %d \n", i);
        i++;
    }
    return 0;
}
*/

/*
#include<stdio.h>

int main(){
    int i = 0;
    while(i <= 20){
       if(i > 4){
        printf("Value of i is %d \n", i);
       };
       i += 5;
    }
    return 0;
}
*/



// ----------Learning about do-while loop.(uncomment below code to execute)--------------

/*
#include<stdio.h>

int main(){
    int i = 0;
    int n;
    printf("Enter how many numbers you want to print: ");
    scanf("%d", &n);
    do{
        printf("%d \n", i+1);
        i++;
    }while(i < n);
    return 0;
}
*/



// ----------Learning about for-loop. (uncomment below code to execute)--------------

/*
#include<stdio.h>

int main(){
    for(int i = 0; i < 10; i++){
        printf("%d \n", i+1);
    }
    return 0;
}
*/

/*
#include<stdio.h>

int main(){
    int i;
    printf("Please enter how many numbers you want to print: ");
    scanf("%d", &i);
    for(i; i; i--){
        printf("%d \n", i);
    }
    return 0;
}
*/

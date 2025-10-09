// ----------------Learning about Arrays.(uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int marks[5] = {50, 45, 95, 78, 82};
    for(int i = 0; i < 5; i++){
        printf("Marks of %d student is %d\n", i+1, marks[i]);
    }
    return 0;
}
*/



// ----------------Learning about Pointer Arithmetic.(uncomment to execute)-----------------------
/*
#include<stdio.h>

int main(){
    int a;
    int *ptr = &a;
    printf("Value of ptr is: %u\n", ptr);
    *ptr++;
    printf("Value of ptr is: %u\n", ptr);
    return 0;
} 
*/



// ----------------Learning about accessing Arrays using Pointers.(uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int marks[4];
    int *ptr = &marks[0];
    for(int i = 0; i < 4; i++){
        printf("Enter the marks of %d student: ", i+1);
        scanf("%d", ptr);
        ptr++;
    }
    for(int i = 0; i < 4; i++){
        printf("Marks of %d student: %d\n", i+1, marks[i]);
    }
    return 0;
}
*/



// ----------------Learning about multi-dimensional Arrays.(uncomment to execute)-----------------------

/*
#include<stdio.h>

int main(){
    int array[3][5];
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("Enter marks of student %d in subject %d: ", i+1, j+1);
            scanf("%d", &array[i][j]);
        }
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            printf("Marks of student %d in subject %d is: %d\n", i+1, j+1, array[i][j]);
        }
    }
    return 0;
}
*/



/*
#include<stdio.h>

int main(){
    int arr[3][5];
    printf("Enter any 15 numbers to push them into 2d array.\n");
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 5; j++){
            scanf("%d", &arr[i][j]);
        }
    }
    printf("{");
    for(int i = 0; i < 3; i++){
        printf("{");
        for(int j = 0; j < 5; j++){
            printf("%d", arr[i][j]);
            if(j < 4){
                printf(", ");
            }
        }
        printf("}");
        if(i < 2){
            printf("\n");
        }
    }
    printf("}");
    return 0;
}
*/
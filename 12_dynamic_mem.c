// ---------------Learning about Malloc(). (Uncomment to execute)-------------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) malloc(6 * sizeof(int));
    for(int i = 0; i < 6; i++){
        printf("Enter the %d number: ", i+1);
        scanf("%d", &ptr[i]);
    }
    for(int i = 0; i < 6; i++){
        printf("%d number is: %d\n", i+1, ptr[i]);
    }
    return 0;
}
*/



/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    float *ptr = (float*) malloc(5 * sizeof(float));
    for(int i = 0; i < 5; i++){
        printf("Enter %d float number: ", i+1);
        scanf("%f", &ptr[i]);
    }
    for(int i = 0; i < 5; i++){
        printf("%d number is: %.2f\n", i+1, ptr[i]);
    }
    return 0;
}
*/



// -----------------Learning about calloc().(Uncomment to execute)----------------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) calloc(6, sizeof(int));
    for(int i = 0; i < 6; i++){
        printf("Value of %d is: %d\n", i+1, ptr[i]);
    }
    return 0;
}
*/



// -------------Learning about free().(Uncomment to execute)---------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) calloc(6, sizeof(int));
    for(int i = 0; i < 6; i++){
        printf("Value of %d is: %d\n", i+1, ptr[i]);
    }
    free(ptr);
    return 0;
}
*/



// -------------Learning about realloc().(Uncomment to execute)---------------

/*
#include<stdio.h>
#include<stdlib.h>

int main(){
    int *ptr = (int*) malloc(6 * sizeof(int));
    for(int i = 0; i < 6; i++){
        printf("Value of %d is: ", i+1);
        scanf("%d", &ptr[i]);
    }
    for(int i = 0; i < 6; i++){
        printf("Value of %d is: %d\n", i+1, ptr[i]);
    }
    ptr = realloc(ptr, 10 * sizeof(int));
    for(int i = 0; i < 10; i++){
        printf("Value of %d is: ", i+1);
        scanf("%d", &ptr[i]);
    }
    for(int i = 0; i < 10; i++){
        printf("Value of %d is: %d\n", i+1, ptr[i]);
    }
    return 0;
}
*/
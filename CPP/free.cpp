#include<stdio.h>
#include<stdlib.h>

int main()
{

    int *ptr, *ptr1;
    int n, i;


    n=5;
    printf("Enter number of elements: %d \n", n);

    ptr = (int*) malloc(n*sizeof(int));

    ptr1 = (int*) calloc(n, sizeof(int));


    if (ptr == NULL || ptr1 == NULL){
        printf("Memory not allocated.\n");
        exit(0);
    }
    else{
        printf("memory successfully allocated using calloc.\n");

        free(ptr1);
        printf("Calloc memory successfully freed.\n");

    }
    return 0;
}

//“free” method in C is used to dynamically de-allocate the memory.
//The memory allocated using functions malloc() and calloc() is not de-allocated on their own.
// Hence the free() method is used, whenever the dynamic memory allocation takes place.
// It helps to reduce wastage of memory by freeing it.

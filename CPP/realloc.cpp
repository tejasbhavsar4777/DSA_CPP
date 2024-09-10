//realloc() method

//“realloc” or “re-allocation” method in C is used to dynamically change
// the memory allocation of a previously allocated memory.
//In other words, if the memory previously allocated with the
// help of malloc or calloc is insufficient, realloc can be used to dynamically re-allocate memory.
// re-allocation of memory maintains the already present value and new blocks will be initialized with the default garbage value.




#include <stdio.h>
#include <stdlib.h>


//----------------------------------------------------------------------------
int main()
{

    // This pointer will hold the
    // base address of the block created
    int* ptr;
    int n, i;

    // Get the number of elements for the array
    printf("Enter number of elements: ");
    scanf("%d",&n);
    printf("Enter number of elements: %d\n", n);

    // Dynamically allocate memory using calloc()
    ptr = (int*)calloc(n, sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    else {

        printf("Memory successfully allocated using calloc.\n");

        // Get the elements of the array
        for (i = 0; i < n; ++i) {
            ptr[i] = i + 1;
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < n; ++i) {
            printf("%d, ", ptr[i]);
        }

        // Get the new size for the array
        printf("\nEnter number of new size array:");
        scanf("%d",&n);
        printf("Enter the new size of the array: %d\n", n);
        //n = 10;
        //printf("\n\nEnter the new size of the array: %d\n", n);



        ptr = (int*)realloc(ptr, n*sizeof(int));
            if (ptr == NULL){
                printf("Reallocation Failed\n");
                exit(0);

            }

        printf("memory successfully re-allocated using realloc.\n");

        for (i=5;i<n;++i){
            ptr[i] = i + 1;

        }

        printf("The elements of array are: ");
        for (i=0;i<n;++i){
            printf("%d,",ptr[i]);

        }

        free(ptr);


    }
    return 0;

}

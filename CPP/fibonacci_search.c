#include<stdio.h>
int min(int x, int y){
    return (x<=y)? x:y;
}
int fibonacciSearch(int arr[], int n, int x){

    int fib2 = 0;
    int fib1 = 1;
    int fibM = fib2 + fib1;

    while (fibM<n){
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib2 + fib1;
    }

    int offset = -1;


    while (fibM > 1){
        int i = min(offset + fib2, n-1);


        if (arr[i] < x){
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        else if (arr[i] > x){
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;

        }
        else{
            return i;
        }

    }

    if (fib1 && arr[offset+1] == x){
        return offset + 1;
    }

    return -1;
}

int main()
{
    int n, x, result;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    printf("Enter the key to search: ");
    scanf("%d", &x);

    result = fibonacciSearch(arr,n,x);

    if (result != -1) {
        printf("Key %d found at position %d.\n", x, result + 1);
    } else {
        printf("Key %d not found in the array.\n", x);
    }

    return 0;
}

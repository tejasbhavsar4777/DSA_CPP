#include <stdio.h>

int binarySearch(int arr[], int low, int high, int x)
{
    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;

        if (arr[mid] < x)
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1;
}



int main() {
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

    result = binarySearch(arr,0,n, x);

    if (result != -1) {
        printf("Key %d found at position %d.\n", x, result + 1);
    } else {
        printf("Key %d not found in the array.\n", x);
    }

    return 0;
}

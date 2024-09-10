#include <stdio.h>

int main() {
    int n, key, i, found = 0;
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];


    for (i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);


    for (i = 0; i < n; i++) {
        if (arr[i] == key) {
            printf("Key %d found at position %d.\n", key, i + 1);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Key %d not found in the array.\n", key);
    }

    return 0;
}

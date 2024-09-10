#include<stdio.h>

int add(int arr[], int n)
{
    int sum = 0;

    for (int i=0;i<n;i++){
        sum+=arr[i];
    }
    return sum;
}
int main() {
    int n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int sum = add(arr, n);


    printf("The sum of the entered numbers is: %d\n", sum);

    return 0;
}

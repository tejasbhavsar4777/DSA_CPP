#include<stdio.h>

void printPrevSmaller(int arr[], int n)
{

    printf(" -1 ");

    for (int i=1;i<n;i++){
        int j;

        for (j=i-1;j>=0;j--){
            if (arr[j]>arr[i]){
                printf(" %d ",arr[j]);
                break;
            }
        }

        if (j==-1)
            printf("%d -1 " );
    }
}
 int main()
 {

     int arr[]={4,10,5,18,3,12,7};
     int n = sizeof(arr)/sizeof(arr[0]);
     printPrevSmaller(arr,n);
     return 0;
 }

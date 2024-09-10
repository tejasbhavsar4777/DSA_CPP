#include<iostream>

using namespace std;

void rotate(int arr[], int n)
{

    int i = 0, j = n - 1;
    while (i != j){
        swap (arr[i], arr[j]);
        i++;
    }
}

int main(){
    int arr[] = {1,2,3,4,5}, i;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout<< "Given Array is \n";
    for (i=0;i<n;i++)
        cout << arr[i] << " ";


    rotate(arr, n);

    cout << "\n Rotated array is \n";
    for (i=0;i<n;i++)
        cout << arr[i] << " ";


    return 0;

}

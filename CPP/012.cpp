//program to cyclically rotate an array by one

#include<iostream>

using namespace std;

void rotate(int arr[], int n)
{

    int last_el = arr[n - 1];


    for (int i = n - 1; i > 0; i--){
        arr[i] = arr[i - 1];
    }

    arr[0] = last_el;
}

int main()
{
    int arr[] = {1,2,3,4,5};
    int n = sizeof(arr) / sizeof(arr[0]);

    cout <<"Given array is \n";
    for (int i = 0; i < n; i++)
        cout<<arr[i]<< " ";

    rotate(arr, n);

    cout << "Rotated array is\n";
    for (int i = 0; i < n; i++)
        cout << arr [i] << " ";

    return 0;
}

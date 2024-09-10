#include<iostream>
using namespace std;

void printArraySized(int arr[3], int n)
{
    cout << "Array as Sized Array Argument: ";
    for (int i=0;i<n;i++){
        cout << arr[i] << " ";

    }
    cout << endl;
}

void PrintArrayUnsized(int arr[], int n)
{


    cout << "Array as Unsized Array Argument: ";
     for (int i=0;i<n;i++){
        cout << *(arr + i) << " ";

    }
    cout << endl;
}

void PrintArraypointer(int* ptr, int n)
{
    cout <<"Array as pointer Argument: ";
    for (int i = 0;i<n;i++){
        cout << ptr[i] << " ";
    }
}

int main()
{

    int arr[] = {10,20,30};
    int n = sizeof(arr) / sizeof(arr[0]);

    printArraySized(arr,n);
    PrintArrayUnsized(arr,n);
    PrintArraypointer(arr,n);

    return 0;
}

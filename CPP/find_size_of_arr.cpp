#include<iostream>
using namespace std;

int main(){

    int arr[] = {1,2,3,4,5};


    int* ptr = arr;



    cout << "Size of arr[0]: " << sizeof(arr[0]) << endl;

    cout << "size of arr: " << sizeof(arr) << endl;

    int n = sizeof(arr) / sizeof(arr[0]);


    cout <<"Length of an array: " << n << endl;



    cout << "Memory address of arr: " << arr << endl;
    cout << "Memory address of arr: " << ptr << endl;
    return 0;




}

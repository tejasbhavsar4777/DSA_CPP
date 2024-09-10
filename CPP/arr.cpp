#include <iostream>
using namespace std;

int main()
{

    int arr[5];
    arr[0] = 5;
    arr[2] = -10;

    arr[3/2] = 2;

    arr[3] = arr[0];


    cout << arr [0] << " " << arr[1] << " " << arr[2] << " " << arr[3];

    return 0;
}


// array is collection of items stored at continuous memory locations. The idea of array is to represent many instance in one variable.

//DataType arrayName[size_of_array];

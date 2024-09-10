#include<iostream>
using namespace std;

int main()
{
    int arr[3];
    int table_of_two[10] = {2,4,6,8,10,12,14,16,18,20};


    arr[0] = 10;
    arr[1] = 20;
    arr[2] = 30;


    cout << "arr[0]: " << arr[0] << endl;
    cout << "arr[1]: " << arr[1] << endl;
    cout << "arr[2]: " << arr[2] << endl;

    cout <<"Table of two: ";

    for (int i=0;i<10;i++){
        cout << table_of_two[i] << " ";

    }
    return 0;
}

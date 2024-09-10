#include<iostream>
using namespace std;
//find unique number

int findUnique(int arr, int size)
{
    int ans = 0;

    for (int i=0;i<size;i++){
        ans = ans^arr[i];
    }
    return ans;


}

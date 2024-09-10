#include<iostream>
using namespace std;


bool search(int arr[], int n, int key){
    for (int i=0; i<n;i++){
        if (arr[i] == key){
            return i;
        }

    }
    return -1;
}

int main()
{

    int arr[] = {5,7,-2,10,22,-2,0,5,22,1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    bool found = search(arr,n,key);

    if (found){
        cout <<"Key is present "<< endl;
    }
    else{
        cout <<"Key is not present"<< endl;
    }

    return 0;
}

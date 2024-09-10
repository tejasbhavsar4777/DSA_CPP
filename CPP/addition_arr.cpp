#include<iostream>

using namespace std;

int sum(int arr[], int n, int key){
    for i in range(n)



}
{

    if (n == 0){
        return 0;
    }
    else{
        return arr[0] + sum(arr + 1, n - 1);
    }
}

int main()
{

    int arr[] = {2,7,1,-4,11};
    int n = sizeof(arr) / sizeof(arr[0]);
    int key = 7;

    bool found = search(arr,n,key);

    if (found){
        cout <<"Key is present "<<endl;
    }
    else{
        cout <<"Key is not present"<<endl;
    }

    return 0;
}

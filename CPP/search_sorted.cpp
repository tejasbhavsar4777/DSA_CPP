#include<bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int low, int high, int x)
{
    while (low<=high){
        int mid = low + (high - low) / 2;
        if (arr[mid] == x) return mid;
        if (arr[mid]<x) low = mid+1;
        else high = mid - 1;
    }
    return -1;

}

int findPivot(vector<int> &arr, int low, int high){
    while(low<high){

        if (arr[low]<=arr[high])
            return low;
        int mid = (low+high)/2;

        if (arr[mid] > arr[high])
            low = mid + 1;

        else
            high = mid;

    }
    return low;
}

int pivotedBinarySearch(vector<int> &arr, int n, int key){
    int pivot = findPivot(arr,0,n-1);

    if (pivot==0)
        return binarySearch(arr,0,n-1,key);

    if (arr[pivot] == key)
        return pivot;

    if (arr[0]<=key)
        return binarySearch(arr,0,pivot-1,key);
    return binarySearch(arr,pivot+1,n-1,key);
}
int main()
{
    vector<int> arr = {5,6,7,8,9,10,1,2,3};
    int key = 3;
    cout << pivotedBinarySearch(arr,arr.size(),key);
    return 0;
}

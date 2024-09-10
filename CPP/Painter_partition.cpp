//Painter partition

#include<climits>
#include<iostream>

using namespace std;

int sum(int arr[], int from, int to)
{
    int total = 0;
    for (int i=from;i<=to;i++)
        total += arr[i];
    return total;
}

 int find_painter(int arr[], int n, int k)
 {
     if (k == 1)
        return sum(arr,0,n-1);
     if (n == 1)
        return arr[0];


     int best = INT_MAX;


     for (int i=1;i<n;i++)
        best = min(best, max(find_painter(arr,i,k-1),sum(arr,i,n-1)));

     return best;

 }

 int main()
 {
     int arr[] = {1,2,3,4};
     int n =  sizeof(arr)/sizeof(arr[0]);
     int k = 2;
     cout << find_painter(arr,n,k) << endl;

     return 0;

 }

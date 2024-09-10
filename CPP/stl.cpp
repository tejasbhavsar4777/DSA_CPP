#include<algorithm>
#include <iostream>
#include<vector>
#include<numeric>

using namespace std;

int main()
{

    int arr[] = {10,20,5,23,42,15};
    int n = sizeof(arr) / sizeof(arr[0]);
    vector<int> vect(arr, arr+n);





    cout << "Vector is: ";
    for (int i=0;i<n;i++)
        cout << vect[i] << " ";

    sort(vect.begin(), vect.end());

    cout  << "\n Vector after sorting is: ";
    for (int i=0;i<n;i++)
        cout << vect[i] << " ";


        sort(vect.begin(), vect.end(), greater<int>());

        cout << "\nVector after sorting in Descending order is: ";
        for (int i=0;i<n;i++)
            cout << vect[i] << " ";


        reverse(vect.begin(), vect.end());


        cout << "\nVector after reversing is: ";
        for (int i=0;i<n;i++)
            cout << vect[i] << " ";




        return 0;
}

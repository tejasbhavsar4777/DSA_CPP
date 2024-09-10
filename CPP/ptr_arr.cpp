#include<iostream>

using namespace std;

void Printarray(int a[10])
{
    for (int i=0;i<5;i++)
        a[i] = a[i] + 5;
}

int main()
{

    int a[5] = {1,2,3,4,5};
    Printarray(a);
    for (int i=0;i<5;i++)
        cout << a[i] << " ";
    return 0;

}

#include<iostream>

using namespace std;

int main()
{
    int x = 5;



    cout << "Initial value of X: " << x << endl;
    x++;

    cout << "After x++ , x is now: " << x << endl;

    int a = 10;
    int b, c;

    b = ++a;

    c = a++;

    cout <<"a: " << a << ",b: " << b << ", c: " << c << endl;

    return 0;
}

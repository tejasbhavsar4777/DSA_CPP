#include<bits/stdc++.h>

using namespace std;

enum GeeksforGeeks {Geek1, Geek2, Geek3};

GeeksforGeeks Ge1 = Geek1;
GeeksforGeeks Ge2 = Geek2;
GeeksforGeeks Ge3 = Geek3;

struct GFG {

    int G1;
    char G2;
    float G3;

};

int main()
{
    struct GFG Geek;

    Geek.G1 = 85;
    Geek.G2 = 'G';
    Geek.G3 = 989.45;
    cout << "The Value is: " << Geek.G1 << endl;
    cout << "The Value is: " << Geek.G2 << endl;
    cout << "The Value is: " << Geek.G3 << endl;

    cout << "The Numerical value "
         << "Assigned to Geek1 : " << Ge1 << endl;


    cout << "The Numerical value "
         << "Assigned to Geek2 : " << Ge2 << endl;


    cout << "The Numerical value "
         << "Assigned to Geek3 : " << Ge3 << endl;


    return 0;



}

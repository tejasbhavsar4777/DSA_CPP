//datatype *var_name;
//pointers are symbolic representation of addresses.
// They enable programs to simulate call-by-reference as well as to create and manipulate dynamic data structures.
//It is general declaration in c/c++ has the format.

#include <iostream>
using namespace std;

void geeks()
{

    int var = 20;

    int* ptr;

    ptr = &var;

    cout <<"value at ptr = " << ptr << "\n";
    cout <<"value at var = " << var << "\n";
    cout <<"value at *ptr = " << *ptr << "\n";
}

int main(){geeks();}

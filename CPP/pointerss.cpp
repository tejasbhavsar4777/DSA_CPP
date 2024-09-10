#include<iostream>

using namespace std;
void geeks()
{

    int var = 20;

    int* ptr;

    ptr = &var;

    cout <<"Value of ptr = " << ptr << "\n";
    cout <<"Value of Var = " << var<< "\n";
    cout <<"Value of *ptr = " <<*ptr << "\n";
}


int main()
{

    int x = 10;
    int *myptr;

    int y = 10;
    int& myref = y;

    y = 30;



    myptr = &x;


    cout << "Value of x is: ";
    cout << x << endl;


    cout <<"Address stored in myptr is: ";
    cout << myptr << endl;


    cout << "Value of x using *myptr is: ";
    cout << *myptr << endl;

    cout << "Value of y is " << y << endl;
    cout << "Value of myref after change in value of y is: " << myref << '\n';

    cout << "Value of &myref after change in value of y is: " << &myref << '\n';

    geeks();



    return 0;

}

#include <iostream>

using namespace std;

int main()
{

    int a = 5;
    int b = 3;

    int bitwise_and = a & b;


    int bitwise_or = a | b;


    int bitwise_xor = a ^ b;


    int bitwise_not = ~a;


    int lef_shift = a << 2;


    int right_shift = a >> 1;


    cout << "AND: " << bitwise_and << endl;
    cout << "OR: " << bitwise_or << endl;
    cout << "XOR: " << bitwise_xor << endl;
    cout << "NOT a: " << bitwise_not << endl;
    cout << " Left Shift : " << lef_shift << endl;
    cout << "Right Shift: " << right_shift << endl;

    return 0;

}

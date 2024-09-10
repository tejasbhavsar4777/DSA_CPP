#include <iostream>
using namespace std;

namespace n1 {
int X = 2;
void fun() {cout << "This is fun() of n1" << endlf; }
}

using namespace n1;

int main()
{

    cout << X << endl;

    fun();

    return 0;

}

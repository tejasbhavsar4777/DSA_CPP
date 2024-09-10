#include <iostream>
using namespace std;

int main()
{
    int age;


    cout << "Enter The Age is to check weather, You are eligible for vote or not: "<< endl;
    cin >> age;

    if (age > 18){
        cout <<"allowed to vote" << endl;
    }
    else {
        cout <<" not allowed to vote " << endl;

    }
    return 0;
}

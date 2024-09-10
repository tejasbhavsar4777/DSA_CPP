#include<iostream>
using namespace std;

union geek {

    int age;
    char grade;
    float GPA;
};
int main()
{


    union geek student1;


    student1.age = 25;
    cout <<"Age: " << student1.age << endl;

}

#include<iostream>

using namespace std;

int main()
{

    string init("This is init");
    string add(" added now");

    string output;


    for (int i=0;init[i] != '\0';i++)
    {
        output += init[i];
    }

    for (int i=0;add[i] != '\0';i++)
    {
        output += add[i];

    }


    cout << output << endl;
    return 0;
}

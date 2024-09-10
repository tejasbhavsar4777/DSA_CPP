//string in c++
//strings are sequences of characters stored in a char array.
//Strings are used to store word and text.

#include<iostream>

using namespace std;

int main(){


    char s[] = "GeeksforGeeks";
    string str("GeeksforGeeks");
    string strr(5, 'G');
    cout << strr;
    cout << s << endl;
    cout << str;
    return 0;
}

#include <iostream>
using namespace std;

int main()
{
   int var = 10;

   const int cons = 24;

   cout << "Initial value:" << endl;
   cout << "Var:" << var << endl;
   cout << "Cons:" << cons << endl;

   var = 24;  // Semicolon added here

   // cons = 0; // This line is invalid because 'cons' is a constant and cannot be modified

   cout << "Final Value:" << endl;
   cout << "var: " << var << endl;
   cout << "cons: " << cons << endl;

   return 0;
}

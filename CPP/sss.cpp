#include <bits/stdc++.h>
using namespace std;

int toDigit (char ch) {return (ch - '0'); }

int sumofSubstrings(string s)
{
    vector<int> v;
    int n = s.length();
    for (int i=0;i<n;i++){
        for (int len=1;len<=n-i;len++){
            string sub = (s.substr(i, len));
            int x = stoi(sub);
            v.push_back(x);

        }
    }
    int res = accumulate(v.begin(), v.end(),0);

    return res;
}

int main()
{
    string num = "12345";
    cout << sumofSubstrings(num) << endl;
    return 0;

}

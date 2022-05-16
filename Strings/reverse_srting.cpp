#include <bits/stdc++.h>
using namespace std;

string reverseString(string str)
{
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;

        cout << reverseString(s) << endl;
    }
    return 0;
}

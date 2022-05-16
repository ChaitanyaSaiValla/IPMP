#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string reverseWords(string S)
    {
        vector<string> a;
        string str = "";
        for (char i : S)
        {
            if (i == '.')
            {
                a.push_back(str);
                str = "";
                continue;
            }
            str += i;
        }
        a.push_back(str);
        str = "";
        reverse(a.begin(), a.end());
        int l = a.size();
        for (int i = 0; i < l - 1; i++)
        {
            str += a[i];
            str += ".";
        }
        str += a[l - 1];
        return str;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        Solution obj;
        cout << obj.reverseWords(s) << endl;
    }
}
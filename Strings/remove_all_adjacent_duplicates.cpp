#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string rremove(string s)
    {
        if (s.size() < 2)
            return s;
        string s1;
        if (s[0] != s[1])
            s1.push_back(s[0]);
        for (int i = 1; i < s.size() - 1; i++)
        {
            if (s[i - 1] != s[i] && s[i] != s[i + 1])
            {
                s1.push_back(s[i]);
            }
        }
        if (s[s.size() - 1] != s[s.size() - 2])
            s1.push_back(s[s.size() - 1]);
        if (s == s1)
            return s;
        return rremove(s1);
    }
};

int main()
{
    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--)
    {
        string s;
        getline(cin, s);
        Solution ob;
        cout << ob.rremove(s) << "\n";
    }
    return 0;
}
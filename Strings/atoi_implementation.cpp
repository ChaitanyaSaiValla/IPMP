#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int atoi(string str)
    {
        int ans = 0;
        int x = 0;
        for (auto i : str)
        {
            if (i == '-')
            {
                x++;
                if (x > 1)
                    return -1;
                continue;
            }
            if ((i - '0') > 9 || (i - '0') < 0)
                return -1;
            ans = ans * 10 + (i - '0');
        }
        return (x) ? -ans : ans;
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
        Solution ob;
        cout << ob.atoi(s) << endl;
    }
}
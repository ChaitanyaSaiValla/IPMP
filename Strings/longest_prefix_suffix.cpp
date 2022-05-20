#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int lps(string s)
    {
        int n = s.length();
        vector<int> prefix(n, 0);
        int i = 1, j = 0, count = 0;
        while (i < n)
        {
            if (s[i] == s[j])
            {
                prefix[i] = ++count;
                j++, i++;
            }
            else if (j == 0 && s[i] != s[j])
            {
                count = 0;
                prefix[i] = count;
                i++;
            }
            else if (j > 0 && s[i] != s[j])
            {
                j = prefix[j - 1];
                count = j;
            }
        }
        return prefix[n - 1];
    }
};

int main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        string str;
        cin >> str;

        Solution ob;

        cout << ob.lps(str) << "\n";
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string smallestWindow(string s, string p)
    {
        int ans = INT_MAX;
        int count = 0, start = 0;
        unordered_map<char, int> m;
        for (auto i : p)
        {
            if (m[i] == 0)
                count++;
            m[i]++;
        }
        int i = 0;
        for (int j = 0; j < s.length(); j++)
        {
            m[s[j]]--;
            if (m[s[j]] == 0)
                count--;
            if (count == 0)
            {
                while (count == 0)
                {
                    if (ans > j - i + 1)
                    {
                        ans = j - i + 1;
                        start = i;
                    }
                    m[s[i]]++;
                    if (m[s[i]] > 0)
                        count++;
                    i++;
                }
            }
        }
        if (ans != INT_MAX)
            return s.substr(start, ans);

        return "-1";
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
        string pat;
        cin >> pat;
        Solution obj;
        cout << obj.smallestWindow(s, pat) << endl;
    }
    return 0;
} 
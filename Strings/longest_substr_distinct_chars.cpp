#include <bits/stdc++.h>
using namespace std;

int longestSubstrDistinctChars(string S)
{
    int ans = 0, start = 0;
    int n = S.length();
    unordered_map<char, int> m;
    for (int i = 0; i < n; i++)
    {
        if (m.find(S[i]) != m.end() && m[S[i]] >= start)
            start = m[S[i]] + 1;
        m[S[i]] = i;
        ans = max(ans, i - start + 1);
    }
    return ans;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        cout << longestSubstrDistinctChars(S) << endl;
    }
}

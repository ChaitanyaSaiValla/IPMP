// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int factorial(int n)
    {
        return (n <= 1) ? 1 : n * factorial(n - 1);
    }
    void updatecount(vector<int> &count, char c)
    {
        for (int i = c; i < 256; i++)
            --count[i];
    }
    int rank(string S)
    {
        int n = S.length();
        int m = factorial(n);
        int ans = 1;
        vector<int> count(256, 0);
        for (auto i : S)
            count[i]++;
        for (auto j : S)
            if (count[j] > 1)
                return 0;
        for (int i = 1; i < 256; i++)
            count[i] += count[i - 1];
        for (int j = 0; j < n; j++)
        {
            m /= n - j;
            ans += count[S[j] - 1] * m;
            updatecount(count, S[j]);
        }
        return ans % 1000003;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;

        Solution ob;
        cout << ob.rank(S) << endl;
    }
    return 0;
}
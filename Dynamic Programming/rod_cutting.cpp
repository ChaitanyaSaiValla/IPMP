#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int bf(int price[], int n, int cap)
    {
        if (n <= 0)
            return 0;
        if (n <= cap)
            return max(price[n - 1] + bf(price, n, cap - n), bf(price, n - 1, cap));
        else
            return bf(price, n - 1, cap);
    }
    int cutRod(int price[], int n)
    {
        if (n <= 0)
            return 0;
        return bf(price, n, n);
    }
};

class Solution2
{
public:
    int dp[1000][1000];
    int m(int price[], int n, int cap)
    {
        if (n <= 0)
            return 0;
        if (dp[n][cap] != -1)
            return dp[n][cap];
        if (n <= cap)
            return dp[n][cap] = max(price[n - 1] + m(price, n, cap - n), m(price, n - 1, cap));
        else
            return dp[n][cap] = m(price, n - 1, cap);
    }
    int cutRod(int price[], int n)
    {
        if (n <= 0)
            return 0;
        memset(dp, -1, sizeof(dp));
        return m(price, n, n);
    }
};
class Solution3
{
public:
    int cutRod(int price[], int n)
    {

        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                if (i <= j)
                {
                    dp[i][j] = max(price[i - 1] + dp[i][j - i], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][n];
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++)
            cin >> a[i];

        Solution3 ob;

        cout << ob.cutRod(a, n) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;
class Solution1
{
public:
    int coinChange(vector<int> &coins, int amount)
    {
        int n = coins.size();
        int dp[n + 1][amount + 1];

        for (int i = 0; i <= amount; i++)
            dp[0][i] = INT_MAX - 1;
        for (int j = 0; j <= n; j++)
            dp[j][0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= amount; j++)
            {
                if (coins[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - coins[i - 1]], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        if (dp[n][amount] == INT_MAX - 1)
            return -1;
        return dp[n][amount];
    }
};
class Solution2
{
public:
    int dp[10001][100];
    int bf(vector<int> &coins, int w, int n)
    {
        if (n == 0 || w == 0)
            return (w == 0) ? 0 : INT_MAX - 1;
        if (dp[w][n] != -1)
            return dp[w][n];
        if (coins[n - 1] <= w)
            return dp[w][n] = min(1 + bf(coins, w - coins[n - 1], n), bf(coins, w, n - 1));
        else
            return dp[w][n] = bf(coins, w, n - 1);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        memset(dp, -1, sizeof(dp));
        int ans = bf(coins, amount, coins.size());
        if (ans == INT_MAX - 1)
            return -1;
        return ans;
    }
};
class Solution3
{
public:
    int bf(vector<int> &coins, int w, int n)
    {
        if (n == 0 || w == 0)
            return (w == 0) ? 0 : INT_MAX - 1;
        if (coins[n - 1] <= w)
            return min(1 + bf(coins, w - coins[n - 1], n), bf(coins, w, n - 1));
        else
            return bf(coins, w, n - 1);
    }
    int coinChange(vector<int> &coins, int amount)
    {
        int ans = bf(coins, amount, coins.size());
        if (ans == INT_MAX - 1)
            return -1;
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<int> arr(m);
        for (int i = 0; i < m; i++)
            cin >> arr[i];
        Solution1 ob;
        cout << ob.coinChange(arr, n) << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= W; j++)
            {
                if (wt[i - 1] <= j)
                {
                    dp[i][j] = max(val[i - 1] + dp[i - 1][j - wt[i - 1]], dp[i - 1][j]);
                }
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][W];
    }
};
class Solution2
{
public:
    int dp[1000][1000];
    int knapsack(int W, int wt[], int val[], int n)
    {
        if (n == 0)
            return 0;
        if (dp[n][W] != -1)
            return dp[n][W];
        if (wt[n - 1] <= W)
        {
            dp[n][W] = max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1), knapsack(W, wt, val, n - 1));
            return dp[n][W];
        }
        else
        {
            dp[n][W] = knapsack(W, wt, val, n - 1);
            return dp[n][W];
        }
    }
    int knapSack(int W, int wt[], int val[], int n)
    {
        if (n == 0)
            return 0;
        memset(dp, -1, sizeof(dp));
        return knapsack(W, wt, val, n);
    }
};

class Solution3
{
public:
    int knapSack(int W, int wt[], int val[], int n)
    {
        if (n == 0 || W == 0)
            return 0;
        if (wt[n - 1] <= W)
        {
            return max(val[n - 1] + knapSack(W - wt[n - 1], wt, val, n - 1), knapSack(W, wt, val, n - 1));
        }
        else
            return knapSack(W, wt, val, n - 1);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;
        int val[n];
        int wt[n];
        for (int i = 0; i < n; i++)
            cin >> val[i];

        for (int i = 0; i < n; i++)
            cin >> wt[i];
        Solution3 ob;
        cout << ob.knapSack(w, wt, val, n) << endl;
    }
    return 0;
}
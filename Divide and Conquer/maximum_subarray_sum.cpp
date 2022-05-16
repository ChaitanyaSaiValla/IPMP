#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> findSubarray(int a[], int n)
    {
        int ans = 0, sum = 0, count = 0;
        vector<int> sol, temp, s;
        for (int i = 0; i < n; i++)
        {
            if (a[i] < 0)
            {
                if (sum > ans)
                {
                    ans = sum;
                    sol.clear();
                    sol = temp;
                }
                sum = 0;
                temp.clear();
                continue;
            }

            sum += a[i];
            temp.push_back(a[i]);

            count++;
            s.push_back(a[i]);

            if (i == n - 1)
            {
                if (sum > ans)
                {
                    sol.clear();
                    sol = temp;
                }
            }
        }
        if (count == n)
            return s;
        if (sol.size() == 0)
            return {-1};
        return sol;
    }
};

void printAns(vector<int> &ans)
{
    for (auto &x : ans)
    {
        cout << x << " ";
    }
    cout << "\n";
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findSubarray(a, n);
        printAns(ans);
    }
    return 0;
}
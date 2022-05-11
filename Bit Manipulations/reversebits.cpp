#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long reversedBits(long long X)
    {
        long long ans = 0;
        for (int i = 0; i < 32; i++)
        {
            ans <<= 1;
            if (X & 1)
                ans++;
            X >>= 1;
        }
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long X;
        cin >> X;
        Solution ob;
        cout << ob.reversedBits(X) << endl;
    }
    return 0;
}
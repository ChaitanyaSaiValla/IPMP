#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int countBitsFlip(int a, int b)
    {
        int count = 0;
        while (a > 0 || b > 0)
        {
            if ((a & 1) != (b & 1))
                count++;
            a >>= 1;
            b >>= 1;
        }
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;

        Solution ob;
        cout << ob.countBitsFlip(a, b) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    unsigned int getFirstSetBit(int n)
    {
        if (n == 0)
            return 0;
        int x = 1, i = 1;
        while (!(n & x))
        {
            x <<= 1;
            i++;
        }
        return i;
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
        Solution ob;
        printf("%u\n", ob.getFirstSetBit(n));
    }
    return 0;
}

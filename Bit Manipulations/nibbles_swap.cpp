#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int swapNibbles(unsigned char x)
    {
        int a = x & 0x0F;
        int b = x & 0xF0;
        return (a << 4 | b >> 4);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        Solution ob;
        cout << ob.swapNibbles(N) << endl;
    }
    return 0;
}
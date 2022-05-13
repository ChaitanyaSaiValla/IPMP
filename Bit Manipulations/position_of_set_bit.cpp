#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findPosition(int N)
    {
        int p, x = 1, count = 0;
        for (int i = 1; i <= 32; i++)
        {
            if (x & N)
            {
                count++;
                p = i;
            }
            x <<= 1;
        }
        if (count == 1)
            return p;
        else
            return -1;
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
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}
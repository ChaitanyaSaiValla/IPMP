#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    float power(float x, int y)
    {
        if (y == 0)
            return 1;
        float a = power(x, y / 2);
        if (y % 2 == 0)
            return a * a;
        else
        {
            if (y > 0)
                return x * a * a;
            else
                return a * a / 2;
        }
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        float X;
        int Y;
        cin >> X >> Y;
        Solution ob;
        cout << ob.power(X, Y) << endl;
    }
    return 0;
}

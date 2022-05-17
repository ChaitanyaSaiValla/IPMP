#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isAnagram(string a, string b)
    {
        unordered_map<char, int> m1, m2;
        if (a.size() != b.size())
            return false;
        for (int i = 0; i < a.size(); i++)
        {
            m1[a[i]]++;
            m2[b[i]]++;
        }
        if (m1 == m2)
            return true;
        return false;
    }
};

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        string c, d;
        cin >> c >> d;
        Solution obj;
        if (obj.isAnagram(c, d))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

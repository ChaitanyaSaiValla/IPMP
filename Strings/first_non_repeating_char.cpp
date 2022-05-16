#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    char nonrepeatingCharacter(string S)
    {
        unordered_map<char, int> m;
        for (auto i : S)
            m[i]++;
        for (auto j : S)
        {
            if (m[j] == 1)
                return j;
        }
        return '$';
    }
};

int main()
{

    int T;
    cin >> T;

    while (T--)
    {
        string S;
        cin >> S;
        Solution obj;
        char ans = obj.nonrepeatingCharacter(S);

        if (ans != '$')
            cout << ans;
        else
            cout << "-1";

        cout << endl;
    }

    return 0;
}

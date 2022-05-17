#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string removeChars(string string1, string string2)
    {
        unordered_map<char, int> m;
        for (auto i : string2)
            m[i]++;
        for (int j = 0; j < string1.size(); j++)
            if (m[string1[j]] > 0)
                string1[j] = '0';
        string1.erase(remove(string1.begin(), string1.end(), '0'), string1.end());
        return string1;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string string1, string2;
        cin >> string1;
        cin >> string2;
        Solution ob;
        cout << ob.removeChars(string1, string2) << endl;
    }
    return 0;
}
#include <bits/stdc++.h>
using namespace std;

class Solution1
{
public:
    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        sort(S.begin(), S.end());
        do
        {
            ans.push_back(S);
        } while (next_permutation(S.begin(), S.end()));
        return ans;
    }
};
class Solution2
{
public:
    void permutation(string S, int l, int r, vector<string> &ans)
    {
        if (l == r)
        {
            ans.push_back(S);
        }
        else
        {
            for (int i = l; i <= r; i++)
            {
                swap(S[l], S[i]);
                permutation(S, l + 1, r, ans);
                swap(S[l], S[i]);
            }
        }
    }
    vector<string> find_permutation(string S)
    {
        vector<string> ans;
        permutation(S, 0, S.size() - 1, ans);
        sort(ans.begin(), ans.end());
        return ans;
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S;
        cin >> S;
        Solution1 ob;
        vector<string> ans = ob.find_permutation(S);
        for (auto i : ans)
        {
            cout << i << " ";
        }
        cout << "\n";
    }
    return 0;
}

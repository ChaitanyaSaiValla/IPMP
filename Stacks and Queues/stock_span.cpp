#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> calculateSpan(int price[], int n)
    {
        vector<int> span(n);
        stack<int> st;
        st.push(0);
        span[0] = 1;
        for (int i = 1; i < n; i++)
        {
            while (!st.empty() && price[st.top()] <= price[i])
                st.pop();

            if (st.empty())
                span[i] = i + 1;
            else
                span[i] = i - st.top();

            st.push(i);
        }
        return span;
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
        int i, a[n];
        for (i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        Solution obj;
        vector<int> s = obj.calculateSpan(a, n);

        for (i = 0; i < n; i++)
        {
            cout << s[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
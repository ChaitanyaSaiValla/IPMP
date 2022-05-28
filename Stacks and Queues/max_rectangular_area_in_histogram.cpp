#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long getMaxArea(long long arr[], int n)
    {
        vector<long long> leftsmall(n, -1), rightsmall(n, n);
        stack<int> st;
        st.push(-1);
        long long area = arr[0];
        int i = 0;
        while (i < n)
        {
            while (!st.empty() && arr[st.top()] > arr[i] && st.top() != -1)
            {
                rightsmall[st.top()] = i;
                st.pop();
            }
            if (i > 0 && arr[i] == arr[i - 1])
                leftsmall[i] = leftsmall[i - 1];
            else
                leftsmall[i] = st.top();
            st.push(i);
            i++;
        }
        for (int j = 0; j < n; j++)
        {
            area = max(area, arr[j] * (rightsmall[j] - leftsmall[j] - 1));
        }
        return area;
    }
};

int main()
{
    long long t;

    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        long long arr[n];
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        Solution ob;
        cout << ob.getMaxArea(arr, n) << endl;
    }
    return 0;
}

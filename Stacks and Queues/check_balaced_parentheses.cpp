#include <bits/stdc++.h>
using namespace std;

bool valid(string s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (st.empty())
            st.push(i);
        else
        {
            if ((i == ')' && st.top() == '(') || (i == '}' && st.top() == '{') || (i == ']' && st.top() == '['))
                st.pop();
            else
                st.push(i);
        }
    }
    if (!st.empty())
        return false;

    return true;
}

int main()
{
    int t;
    cin >> t;
    cin.ignore();
    while (t--)
    {
        string str;
        getline(cin, str);
        cout << valid(str) << endl;
    }
    return 0;
}

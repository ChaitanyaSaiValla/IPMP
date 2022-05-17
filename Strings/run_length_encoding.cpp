#include <bits/stdc++.h>
using namespace std;

string encode(string src)
{
    int count = 0, n = src.length();
    string a = "";
    for (int i = 0; i < n; i++)
    {
        count++;
        if (i == n - 1)
        {
            a += src[n - 1];
            a += to_string(count);
            break;
        }
        if (src[i] != src[i + 1])
        {
            a += src[i];
            a += to_string(count);
            count = 0;
        }
    }

    return a;
}

int main()
{

    int T;
    cin >> T;
    while (T--)
    {
        string str;
        cin >> str;

        cout << encode(str) << endl;
    }
    return 0;
}

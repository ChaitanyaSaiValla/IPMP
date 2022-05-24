#include <bits/stdc++.h>
using namespace std;

class Queue
{
    stack<int> input, output;

public:
    void enqueue(int x)
    {
        input.push(x);
    }

    int dequeue()
    {
        if (input.size() == 0)
            return -1;
        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }
        int ans = output.top();
        output.pop();
        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
        return ans;
    }
};

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        Queue ob;

        int Q;
        cin >> Q;
        while (Q--)
        {
            int QueryType = 0;
            cin >> QueryType;
            if (QueryType == 1)
            {
                int a;
                cin >> a;
                ob.enqueue(a);
            }
            else if (QueryType == 2)
            {
                cout << ob.dequeue() << " ";
            }
        }
        cout << endl;
    }
}
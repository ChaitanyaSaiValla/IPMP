#include <bits/stdc++.h>
using namespace std;

class QueueStack
{
private:
    queue<int> q1;
    queue<int> q2;

public:
    void push(int);
    int pop();
};

void QueueStack ::push(int x)
{
    q1.push(x);
}

int QueueStack ::pop()
{
    if (q1.empty())
        return -1;
    int x = q1.back();
    while (!q2.empty())
        q2.pop();
    int n = q1.size();
    for (int i = 0; i < n - 1; i++)
    {
        q2.push(q1.front());
        q1.pop();
    }
    q1 = q2;
    return x;
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        QueueStack *qs = new QueueStack();

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
                qs->push(a);
            }
            else if (QueryType == 2)
            {
                cout << qs->pop() << " ";
            }
        }
        cout << endl;
    }
}



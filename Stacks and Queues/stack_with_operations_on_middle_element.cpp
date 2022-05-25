#include <bits/stdc++.h>
using namespace std;

class Stackm
{
    struct Node
    {
        int data;
        Node *next;
        Node *prev;

        Node(int data) { this->data = data; }
    };
    Node *head = NULL;
    Node *mid = NULL;
    int size = 0;

public:
    void push(int data)
    {
        Node *temp = new Node(data);
        if (size == 0)
        {
            head = temp;
            mid = temp;
            size++;
            return;
        }

        head->next = temp;
        temp->prev = head;
        head = head->next;
        if (size % 2 == 1)
        {
            mid = mid->next;
        }
        size++;
    }

    int pop()
    {
        int data = -1;
        if (size != 0)
        {
            data = head->data;
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else
            {
                head = head->prev;
                head->next = NULL;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
            }
            size--;
        }
        return data;
    }

    int findMiddle()
    {
        if (size == 0)
        {
            return -1;
        }
        return mid->data;
    }

    void deleteMiddle()
    {
        if (size != 0)
        {
            if (size == 1)
            {
                head = NULL;
                mid = NULL;
            }
            else if (size == 2)
            {
                head = head->prev;
                mid = mid->prev;
                head->next = NULL;
            }
            else
            {
                mid->next->prev = mid->prev;
                mid->prev->next = mid->next;
                if (size % 2 == 0)
                {
                    mid = mid->prev;
                }
                else
                {
                    mid = mid->next;
                }
            }
            size--;
        }
    }
};

int main()
{
    Stackm st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << "Popped : " << st.pop() << endl;
    cout << "Popped : " << st.pop() << endl;
    cout << "Middle Element : " << st.findMiddle() << endl;
    st.deleteMiddle();
    cout << "New Middle Element : " << st.findMiddle() << endl;
    return 0;
}
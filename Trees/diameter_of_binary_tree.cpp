#include <bits/stdc++.h>
using namespace std;

// Tree Creation

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
Node *newNode(int val)
{
    Node *temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

Node *buildTree(string str)
{
    if (str.length() == 0 || str[0] == 'N')
        return NULL;
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);
    Node *root = newNode(stoi(ip[0]));
    queue<Node *> queue;
    queue.push(root);
    int i = 1;
    while (!queue.empty() && i < ip.size())
    {
        Node *currNode = queue.front();
        queue.pop();
        string currVal = ip[i];
        if (currVal != "N")
        {
            currNode->left = newNode(stoi(currVal));
            queue.push(currNode->left);
        }
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];
        if (currVal != "N")
        {
            currNode->right = newNode(stoi(currVal));
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}
class Solution
{
public:
    int getd(Node *root, int *h)
    {
        if (root == NULL)
        {
            *h = 0;
            return 0;
        }
        int lh = 0, rh = 0;
        int ld = getd(root->left, &lh);
        int rd = getd(root->right, &rh);
        *h = max(lh, rh) + 1;
        return max({ld, rd, 1 + lh + rh});
    }
    int diameter(Node *root)
    {
        int h = 0;
        return getd(root, &h);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string s;
        getline(cin, s);
        Node *root = buildTree(s);
        Solution ob;
        cout << ob.diameter(root) << endl;
    }
    return 0;
}
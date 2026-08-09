#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        left = NULL;
        right = 0;
    }
};

Node *buildTree()
{
    cout << "enter data for root" << endl;
    int data;
    cin >> data;

    if (data == -1)
    {
        return nullptr;
    }
    Node *root = new Node(data);

    cout << "enter data for left child of " << data;
    root->left = buildTree();

    cout << "enter data for right child of " << data;
    root->right = buildTree();

    return root;
}

bool kthAncestor(Node *root, int &k, int p)
{
    // base case
    if (!root)
        return false;

    // check for p
    if (root->data == p)
    {
        return true;
    }

    bool leftAns = kthAncestor(root->left, k, p);
    bool rightAns = kthAncestor(root->right, k, p);

    // wapas aa rhe hoge
    // to check kiya left ya right me ans hai ki nahi
    if (leftAns || rightAns)
    {
        k--;
    }
    if (k == 0)
    {
        k = -1;
        cout << "kth ancestor is :" << root->data << endl;
    }
    return leftAns || rightAns;
}

int main()
{

    Node *root = buildTree();

    return 0;
}
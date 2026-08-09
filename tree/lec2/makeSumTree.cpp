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

int convertToSumTree(Node *root)
{
    if (!root)
        return 0;

    int leftAns = convertToSumTree(root->left);
    int rightAns = convertToSumTree(root->right);

    root->data = leftAns + root->data + rightAns;
    return root->data;
}

// gfg parthi
bool isSumTree(Node *root)
{
    // Your code here
    if (!root)
        return true;
    if (!root->left && !root->right)
        return true;

    bool leftAns = isSumTree(root->left);
    bool rightAns = isSumTree(root->right);

    int temp = 0;

    if (root->left)
        temp += root->left->data;
    if (root->right)
        temp += root->right->data;

    if (root->data == temp && leftAns && rightAns)
    {
        // yahi par fasega tu
        // curr node mate niche na bada node no sum joie etle upar upar add karta gaya
        root->data += temp;
        return true;
    }
    return false;
}

int main()
{

    return 0;
}
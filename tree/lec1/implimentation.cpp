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

Node *buildTree(int data)
{
    if (data == -1)
    {
        return nullptr;
    }
    Node *root = new Node(data);

    int leftData;
    cout << "enter data for left child " << data << endl;
    cin >> leftData;
    root->left = buildTree(leftData);

    int rightData;
    cout << "enter data for right child " << data << endl;
    cin >> rightData;
    root->right = buildTree(rightData);

    return root;
}

void levelOrderTraversal1(Node *root)
{
    if (!root)
    {
        return;
    }

    queue<Node *> q;
    q.push(root);

    while (!q.empty())
    {
        Node *currNode = q.front();
        q.pop();
        cout << currNode->data << " ";

        if (currNode->left)
        {
            q.push(currNode->left);
        }
        if (currNode->right)
        {
            q.push(currNode->right);
        }
    }
}

void levelOrderTraversal(Node *root)
{
    if (root == nullptr)
    {
        return;
    }
    queue<Node *> q;
    // initially
    q.push(root);
    q.push(NULL);

    while (!q.empty())
    {
        Node *temp = q.front();
        q.pop();
        if (temp == nullptr)
        {
            cout << endl;
            if (!q.empty()) // imp codition or else infinite loop ma bharai jaisu
            {
                q.push(NULL);
            }
            // q.push(nullptr); // infinite ma ghusi jse
        }
        else
        {
            cout << temp->data << " ";

            if (temp->left) // check that left is not null
            {
                q.push(temp->left);
            }
            if (temp->right) // check that right is not null
            {
                q.push(temp->right);
            }
        }
    }
}

int main()
{

    Node *root;

    int data;
    cout << "enter data for root node" << endl;
    cin >> data;
    root = buildTree(data);

    cout << "Printing : " << endl;

    levelOrderTraversal1(root);

    cout << "Printing : " << endl;

    levelOrderTraversal(root);

    return 0;
}
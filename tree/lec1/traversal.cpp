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

void inorderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // LNR
    inorderTraversal(root->left);
    cout << root->data << " ";
    inorderTraversal(root->right);
}

void preOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // NLR
    cout << root->data << " ";
    inorderTraversal(root->left);
    inorderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    // LRN
    inorderTraversal(root->left);
    inorderTraversal(root->right);
    cout << root->data << " ";
}

int height(Node *root)
{
    if (root == nullptr)
    {
        return 0;
    }

    int leftHeight = height(root->left);
    int rightHeight = height(root->right);

    return max(leftHeight, rightHeight) + 1;
    // +1 bcoz root node ne bhi add karvu padse ne
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
    Node *root = buildTree();

    levelOrderTraversal(root);

    return 0;
}
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
        this->left = NULL;
        this->right = NULL;
    }
};

Node *insertIntoBST(Node *root, int data)
{
    if (root == nullptr)
    {
        // this is the first node we have to create
        root = new Node(data);
        return root;
    }

    // not the first node
    if (data < root->data)
    {
        // insert in left
        root->left = insertIntoBST(root->left, data);
    }
    else
    {
        // insert into right
        root->right = insertIntoBST(root->right, data);
    }
    return root;
}

void takeInput(Node *&root)
{
    int data;
    cin >> data;

    while (data != -1)
    {
        root = insertIntoBST(root, data);
        cin >> data;
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

void preOrderTraversal(Node *root)
{
    // NLR
    if (!root)
        return;

    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

void inOrderTraversal(Node *root)
{
    // LNR
    if (!root)
        return;

    inOrderTraversal(root->left);
    cout << root->data << " ";
    inOrderTraversal(root->right);
}

void postOrderTraversal(Node *root)
{
    // LRN
    if (!root)
        return;

    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

// assuming there are only unique values in tree
Node *findNodeinBST(Node *root, int target)
{
    if (!root)
        return root;

    if (root->data == target)
    {
        return root;
    }

    if (target > root->data)
    {
        // right subtree ma search karo
        return findNodeinBST(root->right, target);
    }
    else
    {
        // left subtree ma search karo
        return findNodeinBST(root->left, target);
    }
}

int minValue(Node *root)
{
    if (!root)
        return -1;

    Node *temp = root;

    while (temp->left)
    {
        temp = temp->left;
    }
    return temp->data;
}

int maxValue(Node *root)
{
    if (!root)
        return -1;

    Node *temp = root;

    while (temp->right)
    {
        temp = temp->right;
    }
    return temp->data;
}

Node *deleteNodeInBST(Node *root, int target)
{
    // base case
    if (!root)
        return 0;

    if (root->data == target)
    {
        // isi ko delete karna hai
        // 4 case
        if (root->left == NULL && root->right == NULL)
        {
            // leaf node
            delete root;
            return NULL;
        }
        else if (root->left == NULL && root->right != NULL)
        {
            Node *child = root->right;
            delete root;
            return child;
        }
        else if (root->left != NULL && root->right == NULL)
        {
            Node *child = root->left;
            delete root;
            return child;
        }
        else
        {
            // both child
            // find inorder predecessor in left subtree
            int inorderPre = maxValue(root->left);
            // replace root->data value with inorder predecessor
            root->data = inorderPre;
            // delete inorder predecessor from left subtree
            root->left = deleteNodeInBST(root->left, inorderPre);
            return root;
        }
    }
    else if (target > root->data)
    {
        // right jana chahiye
        // yahi par fasega tu
        root->right = deleteNodeInBST(root->right, target);
    }
    else if (target < root->data)
    {
        // left jana chahiye
        // yahi par fasega tu
        root->left = deleteNodeInBST(root->left, target);
    }
    return root;
}

Node *bstUsingInorder(int inorder[], int s, int e)
{
    // base case
    if (s > e)
    {
        return NULL;
    }

    int mid = (s + e) / 2;
    int element = inorder[mid];
    Node *root = new Node(element);

    root->left = bstUsingInorder(inorder, s, mid - 1);
    root->right = bstUsingInorder(inorder, mid + 1, e);

    return root;
}

int main()
{
    // 10 20 5 11 17 2 4 8 6 25 15 -1

    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0;
    int e = 8;
    Node *root = bstUsingInorder(inorder, s, e);
    levelOrderTraversal(root);

    return 0;
}
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
        this->left = nullptr;
        this->right = nullptr;
    }
};

int findPosition(int arr[], int n, int element)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == element)
        {
            return i;
        }
    }
    return -1;
}

void createMapping(int inorder[], unordered_map<int, int> &mp, int size)
{
    for (int i = 0; i < size; i++)
    {
        mp[inorder[i]] = i;
    }
}

// build tree from preorder and inorder traversal
// Note : ketla and kaya kaya parameter nakhvana e dhyan rakhvanu
// Note : preIndex ne by reference levu pade bcoz jo hu ek vaar agal na call ma vadhu chhu pachi preIndex vadhi gai chhe to return aavta mare e state maintain rakhvo che hu nai chahto k recursion call thi return thata thata maru preIndex ni value pachi ochi thava lage

Node *buildTreeFromPreOrderInOrder(int inorder[], int preorder[], int size, int &preIndex, int inorderStart, int inorderEnd)
{
    // base case
    if (preIndex >= size || inorderStart > inorderEnd)
    {
        return nullptr;
    }

    // step A :
    int element = preorder[preIndex++];
    Node *root = new Node(element);
    // H/W : aa findPosition O(1) ma thai jse using unordered_map
    int pos = findPosition(inorder, size, element);

    // step B : root->left solve
    root->left = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, pos - 1);

    // step c: root->right solve
    root->right = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, pos + 1, inorderEnd);

    return root;
}

Node *buildTreeFromPostOrderInOrder(int inorder[], int postorder[], int size, int &postIndex, int inorderStart, int inorderEnd, unordered_map<int, int> &mp)
{
    // base case
    if (postIndex < 0 || inorderStart > inorderEnd)
    {
        return nullptr;
    }

    int element = postorder[postIndex--];
    Node *root = new Node(element);
    // H/W : aa findPosition O(1) ma thai jse using unordered_map
    // int pos = findPosition(inorder, size, element);
    int pos = mp[element];

    // solve for root->right
    root->right = buildTreeFromPostOrderInOrder(inorder, postorder, size, postIndex, pos + 1, inorderEnd, mp);

    // solve for root->left
    root->left = buildTreeFromPostOrderInOrder(inorder, postorder, size, postIndex, inorderStart, pos - 1, mp);

    return root;
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
    // int inorder[] = {40, 20, 50, 10, 60, 30, 70};
    // int preorder[] = {10, 20, 40, 50, 30, 60, 70};

    // int size = 7;
    // int preIndex = 0;
    // int inorderStart = 0;
    // int inorderEnd = size - 1;

    // Node *root = buildTreeFromPreOrderInOrder(inorder, preorder, size, preIndex, inorderStart, inorderEnd);

    // cout << "printing : " << endl;
    // levelOrderTraversal(root);

    int inorder[] = {40, 20, 10, 50, 30, 60};
    int postorder[] = {40, 20, 50, 60, 30, 10};

    int size = 6;
    int postIndex = size - 1;
    int inorderStart = 0;
    int inorderEnd = size - 1;

    unordered_map<int, int> mp;
    createMapping(inorder, mp, size);

    Node *root = buildTreeFromPostOrderInOrder(inorder, postorder, size, postIndex, inorderStart, inorderEnd, mp);

    cout << "printing : " << endl;
    levelOrderTraversal(root);

    return 0;
}
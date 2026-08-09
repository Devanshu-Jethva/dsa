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

void printLL(Node *head)
{
    Node *temp = head;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->right;
    }
    cout << endl;
}

void convertIntoSortedDLL(Node *root, Node *&llhead)
{
    if (!root)
    {
        return;
    }

    convertIntoSortedDLL(root->right, llhead);

    // atach root node
    root->right = llhead;

    if (llhead != NULL)
    {
        llhead->left = root;
    }

    // update head
    llhead = root;

    // left subtree linked list
    convertIntoSortedDLL(root->left, llhead);
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

Node *converSortedDLLToBst(Node *&head, int n)
{
    if (n <= 0)
    {
        return NULL;
    }

    Node *leftRoot = converSortedDLLToBst(head, n / 2);

    Node *root = head;
    root->left = leftRoot;

    head = head->right;

    root->right = converSortedDLLToBst(head, n - n / 2 - 1);
    return root;
}

int main()
{
    int inorder[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int s = 0;
    int e = 8;
    Node *root = bstUsingInorder(inorder, s, e);
    levelOrderTraversal(root);

    Node *head = NULL;
    convertIntoSortedDLL(root, head);
    cout << "Linked List: " << endl;
    printLL(head);
    cout << endl;

    Node *root1 = converSortedDLLToBst(head, 9);
    cout << "BST: " << endl;
    levelOrderTraversal(root1);

    return 0;
}
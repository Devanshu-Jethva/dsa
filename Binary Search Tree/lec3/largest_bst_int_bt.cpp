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

class NodeData
{
public:
    int size;
    int minVal;
    int maxVal;
    bool validBST;

    NodeData(){};

    NodeData(int size, int max, int min, bool valid)
    {
        this->size = size;
        this->maxVal = max;
        this->minVal = min;
        this->validBST = valid;
    }
};

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

NodeData *findLargestBST(Node *root, int &ans)
{
    // base case
    if (!root)
    {
        NodeData *temp = new NodeData(0, INT_MIN, INT_MAX, true);
        return temp;
    }

    NodeData *leftAns = findLargestBST(root->left, ans);
    NodeData *rightAns = findLargestBST(root->right, ans);

    // checking current node
    NodeData *currNodeAns = new NodeData();

    currNodeAns->size = leftAns->size + rightAns->size + 1;
    currNodeAns->maxVal = max(root->data, rightAns->maxVal);
    currNodeAns->minVal = min(root->data, leftAns->minVal);

    if (leftAns->validBST && rightAns->validBST && (root->data > leftAns->maxVal && root->data < rightAns->minVal))
    {
        currNodeAns->validBST = true;
    }
    else
    {
        currNodeAns->validBST = false;
    }

    if (currNodeAns->validBST)
    {
        ans = max(ans, currNodeAns->size);
    }

    return currNodeAns;
}

int main()
{

    // 10 20 5 11 17 2 4 8 6 25 15 -1

    Node *root = new Node(5);
    Node *first = new Node(2);
    Node *second = new Node(4);
    Node *third = new Node(1);
    Node *fourth = new Node(3);

    root->left = first;
    root->right = second;
    first->left = third;
    first->right = fourth;

    levelOrderTraversal(root);
    int ans = 0;
    findLargestBST(root, ans);
    cout << endl;
    cout << "largest bst in binary tree : " << ans << endl;

    return 0;
}
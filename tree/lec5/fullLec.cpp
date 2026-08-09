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

void printTopView(Node *root)
{
    if (!root)
        return;

    // created map for storing horizontal distance : topnode
    map<int, int> topNode;

    // level order traversing
    // we will store a pair consisting of node and Horizontal Distance
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // jo bhi horizontal distance aaya hai check if answer for that hd already exists or not
        if (topNode.find(hd) == topNode.end())
        {
            // this means that search karta karta end sudhi aayi gyu but hd na corresponding Node ni koi entry exist nathi karti and nathi karti to first time aave chhe to entry create kari daisu
            topNode[hd] = frontNode->data;
        }

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // ans is stored in map
    cout << "Printing the answer : " << endl;
    for (auto node : topNode)
    {
        cout << node.first << "->" << node.second << endl;
    }
}

void printBottomView(Node *root)
{
    if (!root)
        return;

    // created map for storing horizontal distance : topnode
    map<int, int> topNode;

    // level order traversing
    // we will store a pair consisting of node and Horizontal Distance
    queue<pair<Node *, int>> q;
    q.push(make_pair(root, 0));

    while (!q.empty())
    {
        pair<Node *, int> temp = q.front();
        q.pop();

        Node *frontNode = temp.first;
        int hd = temp.second;

        // always update entry
        topNode[hd] = frontNode->data;

        if (frontNode->left)
        {
            q.push(make_pair(frontNode->left, hd - 1));
        }
        if (frontNode->right)
        {
            q.push(make_pair(frontNode->right, hd + 1));
        }
    }

    // ans is stored in map
    cout << "Printing the answer : " << endl;
    for (auto node : topNode)
    {
        cout << node.first << "->" << node.second << endl;
    }
}

void printLeftView(Node *root, vector<int> &ans, int level)
{
    // base case
    if (!root)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    // left
    printLeftView(root->left, ans, level + 1);

    // right
    printLeftView(root->right, ans, level + 1);
}

void printRightView(Node *root, vector<int> &ans, int level)
{
    // base case
    if (!root)
        return;

    if (level == ans.size())
    {
        ans.push_back(root->data);
    }

    // right
    printRightView(root->right, ans, level + 1);
    // left
    printRightView(root->left, ans, level + 1);
}

void printLeftBoundary(Node *root)
{
    // base case
    // if root is null then return
    if (root == nullptr)
        return;
    // if root is leaf node then return
    if (root->left == NULL && root->right == NULL)
        return;

    cout << root->data << " ";
    // left side ma process karine aaya ne have right vala ne process nai karva devanhu etle if else ma mukyu chhe k je thi ek j side jai sakie
    // intent e j chhe k left ma javanu jya sudhi leaf na male tya sudhi
    if (root->left)
    {
        printLeftBoundary(root->left);
    }
    else
    {
        printLeftBoundary(root->right);
    }
}
void printLeafBoundary(Node *root)
{
    // base case
    if (root == NULL)
        return;
    // if root is leaf node
    if (root->left == NULL && root->right == NULL)
        cout << root->data << " ";

    printLeafBoundary(root->left);
    printLeafBoundary(root->right);
}

void printRightBoundary(Node *root)
{
    // base case
    if (!root)
        return;
    // if root is leaf node then return
    if (root->left == NULL && root->right == NULL)
        return;

    // right side jaine aaya to hve left ma nai javanu etle if else ma mukyu
    // intent e j chhe k right ma javanu jya sudhi leaf na male tya sudhi
    if (root->right)
    {
        printRightBoundary(root->right);
    }
    else
    {
        printRightBoundary(root->left);
    }

    cout << root->data << " ";
}

void boundyTraversal(Node *root)
{
    if (!root)
        return;

    cout << root->data << " ";
    // A
    printLeftBoundary(root->left);
    // B
    printLeafBoundary(root);
    // C
    printRightBoundary(root->right);
}

int main()
{
    //         10
    //     20      80
    // 30     4050     90
    //     60      70

    // I/P : 10 20 30 -1 -1 40 60 -1 -1 -1 80 50 -1 70 -1 -1 90 -1 -1

    Node *root = buildTree();
    // printTopView(root);
    // printBottomView(root);

    // left view
    // vector<int> ans;
    // int level = 0;
    // printLeftView(root, ans, level);
    // for (int i : ans)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // Right view
    // vector<int> ans;
    // int level = 0;
    // printRightView(root, ans, level);
    // for (int i : ans)
    // {
    //     cout << i << " ";
    // }
    // cout << endl;

    // 10 20 30 -1 -1 50 70 90 -1 -1 80 -1 -1 60 -1 -1 40 -1 100 -1 120 110 -1 -1 130 -1 -1
    boundyTraversal(root);

    return 0;
}
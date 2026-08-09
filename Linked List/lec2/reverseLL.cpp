#include <bits/stdc++.h>
using namespace std;
#define long long ll

class Node
{
public:
    int data;
    Node *next;

    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// inserting new node right at the head of LL
void insertAtHead(Node *&head, Node *&tail, int data)
{
    // if list is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    newNode->next = head;
    head = newNode;
}

void print(Node *&head)
{
    Node *temp = head; // good practice not to use change head
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

Node *reverse(Node *&prev, Node *&curr)
{
    // base case
    if (curr == NULL)
    {
        return prev;
    }

    // 1 case solve kro baki recursion ...
    Node *right = curr->next;
    curr->next = prev;

    reverse(curr, right);
}

Node *reverseUsingLoop(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;

    while (curr != NULL)
    {
        Node *right = curr->next;
        curr->next = prev;
        prev = curr;
        curr = right;
    }
    return prev;
}

Node *reverseUsingRE(Node *&prev, Node *&curr)
{
    if (curr == NULL)
    {
        return prev;
    }

    // 1 case solve kro baki recursion ...
    Node *temp = curr->next;
    curr->next = prev;
    prev = curr;
    curr = temp;

    reverseUsingRE(prev, curr);
}

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 70);
    insertAtHead(head, tail, 60);

    print(head);

    Node *prev = NULL;
    Node *curr = head;

    head = reverse(prev, curr);

    cout << endl;
    print(head);

    head = reverseUsingLoop(head);
    cout << endl;
    print(head);

    prev = NULL;
    curr = head;
    head = reverseUsingRE(prev, curr);
    cout << endl;
    print(head);

    return 0;
}
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

// inserting new node right at the end of LL
void insertAtTail(Node *&head, Node *&tail, int data)
{
    // if list is empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = tail = newNode;
        return;
    }
    Node *newNode = new Node(data);
    tail->next = newNode;
    tail = newNode;
}

int findLength(Node *&head)
{
    Node *temp = head;
    int len = 0;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

void insertAtPosition(Node *&head, Node *&tail, int data, int position)
{
    // if ll empty
    if (head == NULL)
    {
        Node *newNode = new Node(data);
        head = tail = newNode;
        return;
    }
    // find prev & curr
    if (position == 0)
    {
        insertAtHead(head, tail, data);
        return;
    }
    int len = findLength(head);
    if (position >= len)
    {
        insertAtTail(head, tail, data);
        return;
    }
    int i = 1;
    Node *prev = head;
    while (i < position)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;

    Node *newNode = new Node(data);

    newNode->next = curr;

    prev->next = newNode;
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

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertAtHead(head, tail, 20);
    insertAtHead(head, tail, 40);
    insertAtHead(head, tail, 50);
    insertAtHead(head, tail, 70);
    insertAtHead(head, tail, 60);

    // insertAtTail(head, tail, 800);
    // insertAtTail(head, tail, 801);
    // insertAtTail(head, tail, 802);
    // insertAtTail(head, tail, 804);

    print(head);
    cout << endl;
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    cout << endl;

    insertAtPosition(head, tail, 55, 6);

    print(head);
    cout << endl;
    cout << "head : " << head->data << endl;
    cout << "tail : " << tail->data << endl;
    cout << endl;

    return 0;
}
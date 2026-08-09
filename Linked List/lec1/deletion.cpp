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

    ~Node()
    {
        cout << endl
             << "node with value " << this->data << " deleted" << endl;
    }
};

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

void deleteNode(int position, Node *&head, Node *&tail)
{
    if (head == NULL)
    {
        cout << "list is empty" << endl;
        return;
    }

    // deleting first node
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }

    // deleting last node
    int len = findLength(head);
    if (position == len)
    {
        int i = 1;
        Node *prev = head;
        while (i < position - 1)
        {
            prev = prev->next;
            i++;
        }
        prev->next = NULL;
        Node *temp = tail;
        tail = prev;
        delete temp;
        return;
    }

    // deleting middle node
    int i = 1;
    Node *prev = head;
    while (i < position - 1)
    {
        prev = prev->next;
        i++;
    }
    Node *curr = prev->next;
    prev->next = curr->next;
    curr->next = NULL;
    delete curr;
}

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

    deleteNode(5, head, tail);

    cout << endl;
    print(head);

    return 0;
}
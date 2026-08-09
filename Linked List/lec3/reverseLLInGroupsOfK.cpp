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

void print(Node *&head)
{
    Node *temp = head; // good practice not to use change head
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}

int getLength(Node *&head)
{
    int len = 0;
    Node *temp = head;
    while (temp)
    {
        temp = temp->next;
        len++;
    }
    return len;
}

Node *reverseKNodes(Node *&head, int k)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return NULL;
    }
    int len = getLength(head);
    // BC
    if (k > len)
    {
        // cout << "Enter valid value for k " << endl;
        return head;
    }

    // now number of node in LL is >= k then below
    // step 1 : reverse first k nodes of LL
    Node *prev = NULL;
    Node *curr = head;
    Node *forward;

    int count = 0;
    while (count < k)
    {
        forward = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forward;
        count++;
    }
    // step 2 : recursive call
    if (forward != NULL)
    {
        // we still have nodes left to reverse
        head->next = reverseKNodes(forward, k);
    }
    // step 3 : return head of the modified LL
    return prev;
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(40);
    Node *fifth = new Node(50);
    Node *sixth = new Node(60);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;

    print(head);

    cout << endl;

    head = reverseKNodes(head, 3);
    print(head);
    cout << endl;

    return 0;
}
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
    cout << endl;
}

Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *nextNode = curr->next;
    while (curr != NULL)
    {
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

Node *sum(Node *&head1, Node *&head2)
{
    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *temp1 = head1;
    Node *temp2 = head2;
    Node *ansHead = NULL;
    Node *ansTail = ansHead;
    int carry = 0;
    while (temp1 != NULL && temp2 != NULL)
    {
        int sum = temp1->data + temp2->data + carry;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit);
        if (ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }

        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    while (temp1 != NULL)
    {
        int sum = temp1->data + carry;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit);
        if (ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }

        temp1 = temp1->next;
    }

    while (temp2 != NULL)
    {
        int sum = temp2->data + carry;
        int digit = sum % 10;
        carry = sum / 10;

        Node *newNode = new Node(digit);
        if (ansHead == NULL)
        {
            ansHead = newNode;
            ansTail = newNode;
        }
        else
        {
            ansTail->next = newNode;
            ansTail = newNode;
        }

        temp2 = temp2->next;
    }

    while (carry)
    {
        int digit = carry % 10;
        carry = carry / 10;
        Node *newNode = new Node(digit);
        ansTail->next = newNode;
        ansTail = ansTail->next;
    }

    ansHead = reverse(ansHead);

    return ansHead;
}

int main()
{

    Node *head1 = new Node(2);
    Node *second1 = new Node(3);

    head1->next = second1;

    Node *head2 = new Node(2);
    Node *second2 = new Node(3);
    Node *third2 = new Node(4);

    head2->next = second2;
    second2->next = third2;

    cout << "No1 : " << endl;
    print(head1);

    cout << "No2 : " << endl;
    print(head2);

    cout << "No1 + No2 : " << endl;
    Node *ansHead = sum(head1, head2);
    print(ansHead);

    return 0;
}
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
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void removeDuplicates(Node *&head)
{
    if (head == NULL)
    {
        cout << "empty LL " << endl;
        return;
    }
    if (head->next == NULL)
    {
        return;
    }

    // >1 node in LL
    Node *curr = head;

    while (curr != NULL)
    {
        if ((curr->next != NULL) && (curr->data == curr->next->data))
        {
            // equal
            Node *temp = curr->next;
            curr->next = curr->next->next;
            // delete node
            temp->next = NULL; // good practice
            delete temp;
        }
        else
        {
            // not equal
            curr = curr->next;
        }
    }
}

int main()
{
    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(20);
    Node *fourth = new Node(30);
    Node *fifth = new Node(30);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    cout << "input : " << endl;
    print(head);

    removeDuplicates(head);

    cout << "output : " << endl;
    print(head);

    return 0;
}
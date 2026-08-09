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

void insertAtTail(Node *&head, Node *&tail, int data)
{
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

Node *mergeTwoSortedLL(Node *&list1, Node *&list2)
{
    if (list1 == NULL && list2 == NULL)
    {
        return NULL;
    }
    if (list1 == NULL)
    {
        return list2;
    }
    if (list2 == NULL)
    {
        return list1;
    }

    Node *ansHead = NULL;
    Node *ansTail = NULL;
    while (list1 != NULL && list2 != NULL)
    {
        if (list1->data <= list2->data)
        {
            if (ansHead == NULL)
            {
                Node *temp = list1;
                list1 = list1->next;
                ansHead = ansTail = temp;
                temp->next = NULL;
            }
            else
            {
                Node *temp = list1;
                list1 = list1->next;
                ansTail->next = temp;
                ansTail = ansTail->next;
            }
        }
        else
        {
            if (ansHead == NULL)
            {
                Node *temp = list2;
                list2 = list2->next;
                ansHead = ansTail = temp;
                temp->next = NULL;
            }
            else
            {
                Node *temp = list2;
                list2 = list2->next;
                ansTail->next = temp;
                ansTail = ansTail->next;
            }
        }
    }

    while (list1 != NULL)
    {
        Node *temp = list1;
        list1 = list1->next;
        ansTail->next = temp;
        ansTail = ansTail->next;
    }

    while (list2 != NULL)
    {
        Node *temp = list2;
        list2 = list2->next;
        ansTail->next = temp;
        ansTail = ansTail->next;
    }

    return ansHead;
}

int main()
{
    // Linked List 1
    Node *head1 = NULL;
    Node *tail1 = NULL;

    insertAtTail(head1, tail1, 11);
    insertAtTail(head1, tail1, 21);
    insertAtTail(head1, tail1, 51);
    insertAtTail(head1, tail1, 60);

    print(head1);

    // Linked List 2
    Node *head2 = NULL;
    Node *tail2 = NULL;

    insertAtTail(head2, tail2, 1);
    insertAtTail(head2, tail2, 2);
    insertAtTail(head2, tail2, 5);
    insertAtTail(head2, tail2, 68);

    print(head2);

    Node *ansHead = mergeTwoSortedLL(head1, head2);

    print(ansHead);

    return 0;
}
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

void sortZeroOneTwo(Node *&head)
{
    if (head == NULL)
    {
        cout << "empty LL" << endl;
        return;
    }
    if (head->next == NULL)
    {
        // single node
        return;
    }

    int one = 0;
    int two = 0;
    int zero = 0;

    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == 0)
            zero++;
        else if (temp->data == 1)
            one++;
        else if (temp->data == 2)
            two++;

        temp = temp->next;
    }

    temp = head;

    while (zero--)
    {
        temp->data = 0;
        temp = temp->next;
    }
    while (one--)
    {
        temp->data = 1;
        temp = temp->next;
    }
    while (two--)
    {
        temp->data = 2;
        temp = temp->next;
    }
}

Node *sort2(Node *&head)
{
    // create dummy node
    Node *zeroHead = new Node(-1);
    Node *zeroTail = zeroHead;

    Node *oneHead = new Node(-1);
    Node *oneTail = oneHead;

    Node *twoHead = new Node(-1);
    Node *twoTail = twoHead;

    Node *temp;
    while (head != NULL)
    {
        temp = head;
        if (temp->data == 0)
        {
            head = head->next;
            temp->next = NULL;
            zeroTail->next = temp;
            zeroTail = temp;
        }
        else if (temp->data == 1)
        {
            head = head->next;
            temp->next = NULL;
            oneTail->next = temp;
            oneTail = temp;
        }
        else if (temp->data == 2)
        {
            head = head->next;
            temp->next = NULL;
            twoTail->next = temp;
            twoTail = temp;
        }
    }

    // removing oneHead
    temp = oneHead;
    oneHead = oneHead->next;
    temp->next = NULL;
    delete temp;

    // removing twoHead
    temp = twoHead;
    twoHead = twoHead->next;
    temp->next = NULL;
    delete temp;

    // joining lists
    if (oneHead != NULL)
    {
        zeroTail->next = oneHead;
        if (twoHead != NULL)
        {
            oneTail->next = twoHead;
        }
    }
    else
    {
        if (twoHead != NULL)
        {
            zeroTail->next = twoHead;
        }
    }

    // removing zeroHead
    temp = zeroHead;
    zeroHead = zeroHead->next;
    temp->next = NULL;
    delete temp;

    // return head of the LL
    return zeroHead;
}

int main()
{

    Node *head = new Node(0);
    Node *second = new Node(2);
    Node *third = new Node(1);
    Node *fourth = new Node(0);
    Node *fifth = new Node(1);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // print(head);
    // cout << endl;
    // using counting and replacement
    // sortZeroOneTwo(head);
    // print(head);
    // cout << endl;

    // withoud replacements
    print(head);
    cout << endl;
    head = sort2(head);
    print(head);
    cout << endl;

    return 0;
}
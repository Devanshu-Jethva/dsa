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

bool isCircular1pointer(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }
    Node *temp = head;
    Node *ptr = temp->next;
    while (ptr != NULL)
    {
        if (ptr == temp)
        {
            return true;
        }
        ptr = ptr->next;
    }
    // not circular if i reach here
    return false;
}

bool isCircularSlowFast(Node *head)
{
    if (head == NULL)
    {
        cout << "empty" << endl;
        return head;
    }
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        if (fast == slow)
        {
            return true;
        }
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }
    return false;
}

bool isCircularMap(Node *&head)
{
    if (head == NULL)
    {
        return head;
    }
    map<Node *, bool> mp;

    Node *temp = head;
    mp[temp] = true;
    while (temp != NULL)
    {
        if (mp[temp->next])
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
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
    // sixth->next = NULL;
    sixth->next = head;

    cout << "LL is circular or not : " << isCircular1pointer(head) << endl;
    cout << "LL is circular or not : " << isCircularSlowFast(head) << endl;
    cout << "LL is circular or not : " << isCircularMap(head) << endl;

    return 0;
}
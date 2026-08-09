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

Node *reverse(Node *head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = curr->next;
    while (curr != NULL)
    {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    return prev;
}

bool checkPalindrome(Node *&head)
{
    if (head == NULL)
    {
        cout << "LL is empty" << endl;
        return true;
    }
    if (head->next == NULL)
    {
        // only 1 node
        return true;
    }

    // >1 node in LL

    // find middle node
    Node *slow = head;
    Node *fast = head->next; // even => n/2

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            fast = fast->next;
            slow = slow->next;
        }
    }

    // slow pointer is pointing to middle node

    // reverse LL after middle/slow node
    Node *reverseLLKaHead = reverse(slow->next);
    // join the reversed LL into the left part
    slow->next = reverseLLKaHead;

    // start comparison
    Node *temp1 = head;
    Node *temp2 = reverseLLKaHead;

    while (temp2 != NULL)
    {
        if (temp1->data != temp2->data)
        {
            // not a palindrome
            return false;
        }
        else
        {
            // if data is equal, then aage badh jao
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    return true;
}

int main()
{

    Node *head = new Node(10);
    Node *second = new Node(20);
    Node *third = new Node(30);
    Node *fourth = new Node(20);
    Node *fifth = new Node(10);

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;

    // print(head);

    bool isPalindrome = checkPalindrome(head);

    if (isPalindrome)
    {
        cout << "LL is Palindrome" << endl;
    }
    else
    {
        cout << "Not Palindrome" << endl;
    }

    return 0;
}
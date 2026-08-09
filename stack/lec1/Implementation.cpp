#include <bits/stdc++.h>
using namespace std;
#define long long ll

class Stack
{
private:
    int *arr;
    int top;
    int size;

public:
    Stack(int size)
    {
        arr = new int[size];
        this->size = size;
        top = -1;
    }

    // behaviours/functions

    void push(int data)
    {
        if (size - top > 1)
        {
            // space available
            // insert
            top++;
            arr[top] = data;
        }
        else
        {
            // space unavailable
            cout << "Stack overflow" << endl;
        }
    }

    void pop()
    {
        if (top == -1)
        {
            // empty
            cout << "Stack underflow" << endl;
        }
        else
        {
            // not empty
            top--;
        }
    }

    int getTop()
    {
        if (top == -1)
        {
            cout << "stack is empty" << endl;
        }
        else
        {
            return arr[top];
        }
    }

    // return number of valid elements present in stack
    int getSize()
    {
        return top + 1;
    }

    bool isEmpty()
    {
        if (top == -1)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
};

int main()
{

    Stack s(10);

    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);

    while (!s.isEmpty())
    {
        cout << s.getTop() << " ";
        s.pop();
    }
    cout << endl;

    cout << "size of stack now is : " << s.getSize() << endl;

    return 0;
}
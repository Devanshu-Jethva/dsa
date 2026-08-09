#include <bits/stdc++.h>
using namespace std;

class Queue
{
public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void push(int data)
    {
        if (rear == size)
        {
            cout << "overflow" << endl;
        }
        else
        {
            arr[rear] = data;
            rear++;
        }
    }

    void pop()
    {
        if (rear == 0)
        {
            cout << "underflow" << endl;
        }
        else
        {
            arr[front] = INT_MIN;
            front++;
            if (front == rear)
            {
                // queue empty
                front = rear = 0;
            }
        }
    }

    int getFront()
    {
        if (rear == 0)
        {
            cout << "empty" << endl;
            return -1;
        }
        else
        {
            return arr[front];
        }
    }

    bool isEmpty()
    {
        if (rear == 0)
        {
            return true;
        }
        return false;
    }

    int getSize()
    {
        return rear - front;
    }
};

int main()
{
    Queue q(10);

    q.pop();

    q.push(4);
    q.push(4);
    q.push(4);
    q.push(4);

    q.pop();
    q.pop();
    q.pop();
    q.pop();
    q.pop();

    return 0;
}
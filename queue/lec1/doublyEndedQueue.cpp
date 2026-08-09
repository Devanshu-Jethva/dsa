#include <bits/stdc++.h>
using namespace std;

class Deque
{
public:
    int size;
    int *arr;
    int rear;
    int front;

    Deque(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void pushRear(int data)
    {
        // 1.queue full
        // 2.first element
        // 3.circular nature
        // 4.default case
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "overflow";
            return;
        }
        else if (rear == -1)
        {
            front = rear = 0;
        }
        else if (rear == size - 1 && front != 0)
        {
            rear = 0;
        }
        else
        {
            rear++;
        }
        arr[rear] = data;
    }

    void pushFront(int data)
    {
        if ((front == 0 && rear == size - 1) || (rear == front - 1))
        {
            cout << "overflow";
            return;
        }
        else if (rear == -1)
        {
            front = rear = 0;
        }
        else if (front == 0 && rear != size - 1)
        {
            rear = 0;
        }
        else
        {
            front--;
        }
        arr[front] = data;
    }

    void popFront()
    {
        // 1.queue empty
        // 2.single element
        // 3.circular nature
        // 4.default case
        if (rear == -1 && front == -1)
        {
            cout << "empty" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = INT_MIN;
            front = rear = -1;
        }
        else if (front == size - 1)
        {
            arr[front] = INT_MIN;
            front = 0;
        }
        else
        {
            arr[front] = INT_MIN;
            front++;
        }
    }

    void popRear()
    {
        if (rear == -1 && front == -1)
        {
            cout << "empty" << endl;
            return;
        }
        else if (front == rear)
        {
            arr[front] = INT_MIN;
            front = rear = -1;
        }
        else if (rear == 0)
        {
            arr[rear] = INT_MIN;
            rear = size - 1;
        }
        else
        {
            arr[rear] = INT_MIN;
            rear--;
        }
    }
};

int main()
{

    return 0;
}
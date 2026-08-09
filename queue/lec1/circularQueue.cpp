#include <bits/stdc++.h>
using namespace std;

class CQueue
{
public:
    int size;
    int *arr;
    int rear;
    int front;

    CQueue(int size)
    {
        this->size = size;
        arr = new int[size];
        front = rear = -1;
    }

    void push(int data)
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

    void pop()
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
            front++;
        }
    }
};

int main()
{

    return 0;
}
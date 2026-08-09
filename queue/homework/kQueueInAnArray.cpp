#include <bits/stdc++.h>
using namespace std;

class KQueue
{
public:
    int n, k, freespot;
    int *arr, *front, *rear, *next;

    KQueue(int _n, int _k) : n(_n), k(_k), freespot(0)
    {
        arr = new int[n];
        next = new int[n];
        front = new int[k];
        rear = new int[k];
        for (int i = 0; i < k; i++)
            front[i] = rear[i] = -1;

        for (int i = 0; i < n; i++)
            next[i] = i + 1;

        next[n - 1] = -1;
    }

    // push x into qith Queue
    bool push(int x, int qi)
    {
        // overflow
        if (freespot == -1)
        {
            return false;
        }

        // find first free index
        int index = freespot;

        // update freespot
        freespot = next[index];

        // if first element in qi
        if (front[qi] == -1)
        {
            front[qi] = index;
        }
        else
        {
            // link new element to that q's rearest element
            next[rear[qi]] = index;
        }

        // update next
        next[index] = -1;

        // update rear
        rear[qi] = index;
        arr[index] = x;
        return true;
    }

    // pop element fron qith Queue
    int pop(int qi)
    {
        // underflow
        if (front[qi] == -1)
        {
            return -1;
        }

        // find index
        int index = front[qi];

        // front update
        front[qi] = next[index];

        // update freespot
        next[index] = freespot;
        freespot = index;

        return arr[index];
    }

    ~KQueue()
    {
        delete[] arr;
        delete[] front;
        delete[] rear;
        delete[] next;
    }
};

int main()
{

    KQueue q(8, 3);
    cout << q.push(1, 0) << endl;
    cout << q.push(2, 0) << endl;
    cout << q.push(5, 1) << endl;
    cout << q.push(3, 0) << endl;
    cout << q.pop(1) << endl;
    cout << q.pop(0) << endl;
    cout << q.push(7, 0) << endl;
    cout << q.pop(0) << endl;
    cout << q.pop(0) << endl;
    cout << q.pop(0) << endl;
    cout << q.pop(0) << endl;

    return 0;
}
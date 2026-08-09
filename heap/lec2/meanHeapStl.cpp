#include <bits/stdc++.h>
using namespace std;

class custom
{
public:
    bool operator()(int a, int b)
    {
        return a > b;
    }
};

int main()
{
    // min-heap
    // priority_queue<int, vector<int>, greater<int> > pq;
    priority_queue<int, vector<int>, custom> pq;
    // int - data type stored in my pq
    // vector<int> - container

    // greater<int> - comparator
    // Return Value: It returns boolean variable as shown below:
    // True: If two element say(a & b) such that a > b.
    // False: If a < b.

    pq.push(3);
    pq.push(6);
    pq.push(9);
    pq.push(4);
    pq.push(8);

    cout << "top element : " << pq.top() << endl;
    pq.pop();
    cout << "size : " << pq.size() << endl;
    cout << "top element : " << pq.top() << endl;
    pq.pop();
    cout << "top element : " << pq.top() << endl;
    pq.pop();
    cout << "top element : " << pq.top() << endl;
    pq.pop();

    cout << "size: " << pq.size() << endl;
    if (pq.empty())
    {
        cout << "Max heap is empty" << endl;
    }
    else
    {
        cout << "Max heap is not empty" << endl;
    }

    return 0;
}
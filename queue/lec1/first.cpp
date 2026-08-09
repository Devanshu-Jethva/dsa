#include <bits/stdc++.h>
using namespace std;

int main()
{
    queue<int> q;

    q.push(5);
    q.push(25);
    q.push(53);
    q.push(25);
    q.push(52);

    cout << "size of queue is : " << q.size() << endl;

    q.pop();

    cout << "size of queue is : " << q.size() << endl;

    if (q.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }

    cout << "Front element is : " << q.front() << endl;

    return 0;
}
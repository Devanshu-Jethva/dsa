#include <bits/stdc++.h>
using namespace std;

void reverseK(queue<int> &q, int k)
{
    if (k <= 0 || k > q.size())
    {
        return;
    }
    stack<int> st;

    int count = 0;
    while (!q.empty())
    {
        if (count == k)
            break;

        st.push(q.front());
        q.pop();
        count++;
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
    }

    count = 0;
    int n = q.size();
    while (!q.empty())
    {
        if (count == (n - k))
        {
            break;
        }
        q.push(q.front());
        q.pop();
        count++;
    }
}

int main()
{
    queue<int> q;
    q.push(3);
    q.push(6);
    q.push(9);
    q.push(2);
    q.push(8);

    reverseK(q, 5);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
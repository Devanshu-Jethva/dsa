#include <bits/stdc++.h>
using namespace std;

void reverseRE(queue<int> &q)
{
    // base case
    if (q.empty())
    {
        return;
    }

    int temp = q.front();
    q.pop();
    reverseRE(q);
    q.push(temp);
}

void reverseUsingStack(queue<int> &q)
{
    stack<int> st;

    while (!q.empty())
    {
        st.push(q.front());
        q.pop();
    }

    while (!st.empty())
    {
        q.push(st.top());
        st.pop();
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

    // #1
    // reverseUsingStack(q);
    // cout << "Using stack : " << endl;
    // while (!q.empty())
    // {
    //     cout << q.front() << " ";
    //     q.pop();
    // }
    // cout << endl;

    // #2
    reverseRE(q);
    cout << "Using recursion : " << endl;
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
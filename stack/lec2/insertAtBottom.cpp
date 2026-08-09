#include <bits/stdc++.h>
using namespace std;

void solve(stack<int> &st, int target)
{
    if (st.empty())
    {
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();
    solve(st, target);
    st.push(topElement);
}

void insertAtBottom(stack<int> &st)
{
    if (st.empty())
    {
        cout << "Stack is empty " << endl;
    }
    int target = st.top();
    st.pop();
    solve(st, target);
}

int main()
{

    stack<int> st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    st.push(50);

    insertAtBottom(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    return 0;
}
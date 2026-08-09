#include <bits/stdc++.h>
using namespace std;

void insertAtBottom(stack<int> &st, int target)
{
    if (st.empty())
    {
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertAtBottom(st, target);
    st.push(topElement);
}

void reverseStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int topElement = st.top(); // is element ko insertAtBottom karenge pr tab jab stack reverse ho gaya hoga
    st.pop();

    reverseStack(st);
    insertAtBottom(st, topElement);
}

int main()
{
    stack<int> st;
    st.push(40);
    st.push(20);
    st.push(90);
    st.push(10);
    st.push(50);

    // stack right now -> 50 10 90 20 40

    reverseStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}
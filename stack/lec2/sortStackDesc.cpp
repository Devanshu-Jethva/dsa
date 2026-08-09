#include <bits/stdc++.h>
using namespace std;

void insertInOrder(stack<int> &st, int target)
{
    if (st.empty())
    {
        st.push(target);
        return;
    }
    if (st.top() <= target)
    {
        st.push(target);
        return;
    }

    int topElement = st.top();
    st.pop();
    insertInOrder(st, target);
    st.push(topElement);
}

void sortStack(stack<int> &st)
{
    // base case
    if (st.empty())
    {
        return;
    }

    int topElement = st.top();
    st.pop();
    sortStack(st);
    insertInOrder(st, topElement);
}

int main()
{

    stack<int> st;
    st.push(40);
    st.push(20);
    st.push(20);
    st.push(90);
    st.push(50);
    st.push(10);

    sortStack(st);

    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }

    cout << endl;

    return 0;
}
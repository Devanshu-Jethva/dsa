#include <bits/stdc++.h>
using namespace std;
#define long long ll

int main()
{

    // creation
    stack<int> st;

    // insertion
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);

    // remove
    st.pop();

    // check element on top
    cout << "Top element right now is : " << st.top() << endl;

    // size
    cout << "Size of stack is : " << st.size() << endl;

    // isEmpty
    if (st.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "Not empty" << endl;
    }

    stack<int> s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50);

    while (!s.empty())
    {
        cout << s.top() << " ";
        s.pop();
    }
    cout << endl;

    return 0;
}
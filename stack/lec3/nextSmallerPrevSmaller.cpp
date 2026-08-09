#include <bits/stdc++.h>
using namespace std;

vector<int> prevSmallerElement(vector<int> input)
{

    // left to right - prev smaller
    stack<int> st;
    st.push(-1);
    vector<int> ans(input.size());

    for (int i = 0; i < input.size(); i++)
    {
        int curr = input[i];

        // curr element karta smaller na male tya sudhi pop karyu
        while (st.top() >= curr)
        {
            st.pop();
        }

        // mali gayu to ans store
        ans[i] = st.top();

        // curr element ne push kari didhu
        st.push(curr);
    }
    return ans;
}

vector<int> nextSmallerElement(vector<int> input)
{
    // right to left - next smaller

    stack<int> st;
    st.push(-1);
    vector<int> ans(input.size());

    for (int i = input.size() - 1; i >= 0; i--)
    {
        int curr = input[i];

        // ans stack me
        // curr element karta smaller na male tya sudhi pop karyu
        while (st.top() >= curr)
        {
            st.pop();
        }

        // ans mali gayu -> ans store
        ans[i] = st.top();

        // curr element ne push kari do
        st.push(curr);
    }
    return ans;
}

int main()
{

    vector<int> v{2, 1, 3, 4, 1};

    vector<int> ans = nextSmallerElement(v);

    cout << "next smaller" << endl;
    for (int i : ans)
    {
        cout << i << " ";
    }
    cout << endl;

    vector<int> ans2 = prevSmallerElement(v);
    cout << "prev smaller" << endl;
    for (int i : ans2)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
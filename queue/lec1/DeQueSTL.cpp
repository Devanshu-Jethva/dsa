#include <bits/stdc++.h>
using namespace std;

int main()
{

    deque<int> dq;

    dq.push_back(5);
    dq.push_front(15);
    dq.push_back(23);
    dq.push_front(54);

    cout << "Size : " << dq.size() << endl;

    cout << "back element before : " << dq.back() << endl;
    dq.pop_back();
    cout << "back element after : " << dq.back() << endl;

    cout << "front element before : " << dq.front() << endl;
    dq.pop_front();
    cout << "front element after : " << dq.front() << endl;

    return 0;
}
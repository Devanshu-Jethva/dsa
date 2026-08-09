#include <bits/stdc++.h>
using namespace std;

int main()
{
    string text = "Cat is a domestic animal. Fox is a wild Animal. Fox can eat Cat but Cat cannot eat Fox.";

    int pos = text.find("Cat");
    // cout << pos << endl;
    while (pos != string::npos)
    {
        text.replace(pos, 3, "tem");
        pos = text.find("Cat");
    }

    pos = text.find("Fox");
    while (pos != string::npos)
    {
        text.replace(pos, 3, "Cat");
        pos = text.find("Fox");
    }

    pos = text.find("tem");
    while (pos != string::npos)
    {
        text.replace(pos, 3, "Fox");
        pos = text.find("tem");
    }

    cout << text << endl;

    return 0;
}

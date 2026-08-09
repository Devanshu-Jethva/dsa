#include <bits/stdc++.h>
using namespace std;

int main()
{

    unordered_map<string, int> mp;

    // 1.
    pair<string, int> p = make_pair("CSK", 1);
    mp.insert(p);

    // 2.
    pair<string, int> p2("GT", 0);
    mp.insert(p2);

    // 3.
    mp["RCB"] = -1;

    cout << mp.at("CSK") << endl;
    // cout << mp.at("LSG") << endl; // error

    cout << mp.count("CSK") << endl;
    cout << mp.count("MI") << endl;
    if (mp.find("GT") != mp.end())
    {
        cout << "GT found" << endl;
    }
    else
    {
        cout << "GT not found" << endl;
    }

    cout << mp.size() << endl;
    cout << mp["RCG"] << endl;
    cout << mp.size() << endl;

    cout << "printing" << endl;
    for (auto i : mp)
    {
        cout << i.first << " -> " << i.second << endl;
    }

    return 0;
}
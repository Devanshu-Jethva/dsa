#include <bits/stdc++.h>
using namespace std;
#define long long ll

bool compare(string a, string b)
{
    if (a.length() != b.length())
    {
        return false;
    }
    else
    {
        for (int i = 0; i < a.length(); i++)
        {
            if (a[i] != b[i])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{

    /*
    string str;
    // cin >> str;
    getline(cin, str);
    cout << str << endl;

    cout << str.length() << endl;
    cout << "isEmpty" << str.empty() << endl;
    cout << str.substr(0, 3) << endl; // substr(start, length)
    str.pop_back();
    str.push_back('A');
    cout << str << endl;
    */

    /*
    string str1 = "Devanshu";
    string str2 = "devansh";
    str1.compare(str2);
    if (compare(str1, str2))
    {
        cout << "str1 and str2 are same" << endl;
    }
    else
    {
        cout << "not same" << endl;
    }
    */
    /*
    string str = "hello hello hello";

    if (str.find("aldsfjs") == string::npos)
    {
        cout << "not found" << endl;
    }
    else
    {
        cout << "found" << endl;
    }

    // cout << str.find("dasfs") << endl;
    */

    string str = "jaldjfl sjadsa";
    str.replace(0, 5, "adjsd");
    cout << str << endl;

    str.erase(0, 4);
    cout << str << endl;

    return 0;
}
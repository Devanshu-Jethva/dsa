#include <bits/stdc++.h>
using namespace std;
#define long long ll

void printSubsequences(string s, int i, string output)
{
    // base case
    if (i >= s.length())
    {
        cout << output << endl;
        return;
    }

    // include
    output.push_back(s[i]);
    printSubsequences(s, i + 1, output);
    output.pop_back();
    // exclude
    printSubsequences(s, i + 1, output);
}

int main()
{

    string s = "abc";
    int i = 0;
    string output = "";
    printSubsequences(s, i, output);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define long long ll

void printSubsequence(string str, string output, int i, vector<string> &v)
{
    // base case
    if (i == str.length())
    {
        v.push_back(output);
        // cout<<output<<endl;
        return;
    }

    // include
    // output.push_back(str[i]);
    // printSubsequence(str, output, i + 1, v);
    // output.pop_back();

    // exclude
    // jo apde pella include valu recursive function call karyu hot to aapde exclude mate call karya pella ene pachu remove bhi karvu padet - na samjayu hoi to dry run kar
    // output.push_back(str[i]);
    // printSubsequence(str, output, i + 1, v);

    // include
    printSubsequence(str, output + str[i], i + 1, v);
    // exclude
    printSubsequence(str, output, i + 1, v);
}

int main()
{

    string str = "abc";

    string output = "";

    vector<string> v;

    int i = 0;
    printSubsequence(str, output, i, v);
    cout << "all subsequences are : " << endl;
    for (auto s : v)
    {
        cout << s << endl;
    }

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define long long ll

void printPermutation(string &str, int i)
{
    // base case
    if (i >= str.length())
    {
        cout << str << " ";
        return;
    }

    for (int j = i; j < str.length(); j++)
    {
        // swap
        swap(str[i], str[j]);

        // rec call
        printPermutation(str, i + 1);

        // backtracking - to recreate the original input string - because here we have done pass by reference
        // ek case explore karyu have pachu bijo rasto explore karva e point par to pachu aavu padse ne etle
        swap(str[i], str[j]);
    }
}

int main()
{

    // print all permutations of a string
    string s = "abc";

    int i = 0;
    printPermutation(s, i);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;
#define long long ll

bool isPalindrome(string &s, int i, int j)
{
    if (i >= j)
    {
        return true;
    }

    if (s[i] != s[j])
        return false;

    isPalindrome(s, ++i, --j);
}

int main()
{

    string s = "absdfba";
    int i = 0;
    int j = s.size() - 1;

    if (isPalindrome(s, i, j))
    {
        cout << "is palindrome";
    }
    else
    {
        cout << "not palindrome";
    }

    return 0;
}
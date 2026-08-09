#include <bits/stdc++.h>
using namespace std;
#define long long ll

int getLength(char name[])
{
    int count = 0;
    int i = 0;
    while (name[i] != '\0')
    {
        count++;
        i++;
    }
    return count;
}

bool isPalindrome(char arr[])
{
    int s = 0;
    int e = getLength(arr) - 1;
    while (s < e)
    {
        if (arr[s] == arr[e])
        {
            s++;
            e--;
        }
        else
        {
            return false;
        }
    }
    return true;
}

int main()
{

    char arr[100];
    cin.getline(arr, 50);

    if (isPalindrome(arr))
    {
        cout << "palindrome" << endl;
    }
    else
    {
        cout << "not palindrome" << endl;
    }

    return 0;
}
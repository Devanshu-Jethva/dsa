#include <bits/stdc++.h>
using namespace std;
#define long long ll

int getLength(char name[])
{
    int count = 0;
    int i = 0;
    while (name[i] != 0) //  OR name[i] != '\0'
    {
        count++;
        i++;
    }
    return count;
}

int main()
{

    char name[100];
    cout << "Enter string : ";
    cin >> name;

    cout << "lenght : " << getLength(name) << endl;
    cout << "lenght : " << strlen(name) << endl;

    return 0;
}
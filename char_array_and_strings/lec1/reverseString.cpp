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

void reverse(char name[])
{
    int s = 0;
    int e = getLength(name) - 1;
    while (s < e)
    {
        swap(name[s], name[e]);
        s++;
        e--;
    }
    cout << "reversed string : " << name << endl;
}

int main()
{

    char name[100] = {'d', 'e', 'v', 'a', 'n', 's', 'h'};

    cout << "original stirng : " << name << endl;
    reverse(name);
    return 0;
}
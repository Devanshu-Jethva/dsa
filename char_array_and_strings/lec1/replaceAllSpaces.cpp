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

int main()
{

    char arr[100];
    cin.getline(arr, 50);

    int i = 0;
    while (arr[i] != '\0')
    {
        if (arr[i] == ' ')
        {
            arr[i] = '@';
        }
        i++;
    }

    cout << arr << endl;

    return 0;
}
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

void toUppercase(char arr[])
{
    for (int i = 0; i < getLength(arr); i++)
    {
        if (arr[i] == ' ' || arr[i] >= 65 && arr[i] <= 90)
        {
            continue;
        }

        arr[i] = arr[i] - 'a' + 'A';
    }
}

void toLowercase(char arr[])
{
    for (int i = 0; i < getLength(arr); i++)
    {
        if (arr[i] == ' ' || (arr[i] >= 97 && arr[i] <= 122))
        {
            continue;
        }
        arr[i] = arr[i] - 'A' + 'a';
    }
}

int main()
{

    char arr[100];
    cout << "Enter string : ";
    cin.getline(arr, 50);
    cout << "Input : ";
    cout << arr << endl;

    toUppercase(arr);
    cout << "Upper case : ";
    cout << arr << endl;

    toLowercase(arr);
    cout << "Lower case : ";
    cout << arr << endl;

    return 0;
}
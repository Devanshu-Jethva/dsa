#include <bits/stdc++.h>
using namespace std;
#define long long ll

void findMissing(vector<int> arr)
{
    // // visiting method
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     int index = abs(arr[i]);
    //     if (arr[index - 1] > 0)
    //     {
    //         arr[index - 1] *= -1;
    //     }
    // }
    // // for (int i = 0; i < arr.size(); i++)
    // // {
    // //     cout << arr[i] << " ";
    // // }
    // for (int i = 0; i < arr.size(); i++)
    // {
    //     if (arr[i] > 0)
    //     {
    //         cout << i + 1 << " ";
    //     }
    // }

    // sorting + swaping

    int i = 0;
    while (i < arr.size())
    {
        int index = arr[i] - 1;
        if (arr[index] != arr[i])
        {
            swap(arr[i], arr[index]);
        }
        else
        {
            i++;
        }
    }
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] != i + 1)
        {
            cout << i + 1 << " ";
        }
    }
}

int main()
{
    vector<int> v{1, 3, 3, 3, 2};

    findMissing(v);

    return 0;
}
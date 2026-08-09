#include <bits/stdc++.h>
using namespace std;
#define long long ll

void print(int *arr, int &n, int i)
{
    // base case
    if (i >= n)
    {
        return;
    }
    // 1 case solved
    cout << arr[i] << " ";
    // baki recursion sambhal lenga
    print(arr, n, i + 1);
}

int main()
{

    int arr[5] = {1, 2, 3, 4, 5};
    int n = 5;

    int i = 0;
    print(arr, n, i);

    return 0;
}
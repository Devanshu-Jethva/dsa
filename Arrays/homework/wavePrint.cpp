#include <bits/stdc++.h>
using namespace std;
#define long long ll

void wavePrint(vector<vector<int>> arr)
{
    int col = 0;
    while (col < arr[0].size())
    {
        if ((col & 1) == 0)
        {
            for (int i = 0; i < arr.size(); i++)
            {
                cout << arr[i][col] << ' ';
            }
        }
        else
        {
            for (int i = arr.size() - 1; i >= 0; i--)
            {
                cout << arr[i][col] << ' ';
            }
        }
        col++;
    }
}

int main()
{

    vector<vector<int>> arr = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}};
    wavePrint(arr);

    return 0;
}
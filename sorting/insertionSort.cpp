#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{3, 3, 5, 7, 8, 64, 3, 23, 45, 6, 78, 8, 6, 4};
    int n = arr.size();

    for (int i = 1; i < n; i++)
    {
        int ele = arr[i];
        int j;
        for (j = i - 1; j >= 0; j--)
        {
            if (arr[j] > ele)
            {
                arr[j + 1] = arr[j];
            }
            else
            {
                break;
            }
        }
        arr[j + 1] = ele;
    }

    for (auto i : arr)
    {
        cout << i << " ";
    }

    return 0;
}
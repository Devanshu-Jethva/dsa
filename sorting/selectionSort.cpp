#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> arr{3, 3, 5, 7, 8, 64, 3, 23, 45, 6, 78, 8, 6, 4};
    int n = arr.size();

    for (int i = 0; i < n - 1; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        swap(arr[minIndex], arr[i]);
    }

    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
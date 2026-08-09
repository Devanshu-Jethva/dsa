#include <bits/stdc++.h>
using namespace std;
#define long long ll

int solve(vector<int> arr)
{
    int s = 0;
    int e = arr.size();

    int mid = s + (e - s) / 2;
    while (s <= e)
    {
        // single element
        if (s == e)
        {
            return s;
        }
        if ((mid & 1) == 0)
        {
            // even
            if (arr[mid] == arr[mid + 1])
            {
                // left par ubha chhie => right search
                s = mid + 2;
            }
            else
            {
                // right par chhie , mid might be ans bcoz mid is even and ans will always be even => left search like this
                e = mid;
            }
        }
        else
        {
            // odd
            if (arr[mid] == arr[mid - 1])
            {
                // left par ubha chhie => right search
                s = mid + 1;
            }
            else
            {
                // right par chhie , mid can never be ans bcoz mid is odd and ans always be even => left search like this
                e = mid - 1;
            }
        }
        mid = s + (e - s) / 2;
    }

    return -1;
}

int main()
{

    vector<int> arr{1, 1, 2, 2, 3, 3, 4, 4, 3, 600, 600, 4, 4};
    int ans = solve(arr);
    cout << "index is " << ans << endl;
    cout << "value is " << arr[ans] << endl;

    return 0;
}
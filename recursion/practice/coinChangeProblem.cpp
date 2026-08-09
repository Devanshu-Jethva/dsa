// by subracting value of coins from target amount

// #include <bits/stdc++.h>
// using namespace std;
// #define long long ll

// int solve(vector<int> &coins, int target)
// {
//     // base case
//     if (target == 0)
//     {
//         return 0;
//     }
//     if (target < 0)
//         return INT_MAX;

//     // 1 case solve karsu
//     int mini = INT_MAX;
//     for (int i = 0; i < coins.size(); i++)
//     {
//         int ans = solve(coins, target - coins[i]);

//         if (ans != INT_MAX)
//         {
//             mini = min(mini, ans + 1);
//         }
//     }
//     return mini;
// }

// int main()
// {

//     vector<int> coins{3};

//     int target = 11;
//     int ans = solve(coins, target);
//     if (ans == INT_MAX)
//     {
//         cout << "Cant make the target " << endl;
//         return 0;
//     }

//     cout << "Minimum No. of Coins needed to make " << target << " is : "
//          << ans << endl;
//     return 0;
// }
//
//
//

//
//
//
//

// by adding value of coins and checking if target amount is reached or not

#include <bits/stdc++.h>
using namespace std;
#define long long ll

int solve(vector<int> &coins, int &target, int current)
{
    // base case
    if (current == target)
    {
        return 0;
    }
    if (current > target)
    {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for (int i = 0; i < coins.size(); i++)
    {
        int ans = solve(coins, target, current + coins[i]);
        if (ans != INT_MAX)
        {
            mini = min(mini, ans + 1);
        }
    }
    return mini;
}

int main()
{

    vector<int> coins{1, 9, 6, 3, 10, 11, 5};

    int target = 11;
    int current = 0;
    int ans = solve(coins, target, current);
    if (ans == INT_MAX)
    {
        cout << "Cant make the target " << endl;
        return 0;
    }

    cout << "Minimum No. of Coins needed to make " << target << " is : "
         << ans << endl;
    return 0;
}

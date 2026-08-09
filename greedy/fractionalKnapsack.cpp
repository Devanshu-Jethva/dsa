#include <bits/stdc++.h>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b)
{
    double ratio1 = a.first / (double)a.second;
    double ratio2 = b.first / (double)b.second;

    return ratio1 > ratio2;
}

int main()
{
    int val[] = {60, 100, 120};
    int wt[] = {10, 20, 30};
    int capacity = 50;

    int n = 3;
    vector<pair<int, int>> data;
    for (int i = 0; i < n; i++)
    {
        data.push_back({val[i], wt[i]});
    }

    sort(data.begin(), data.end(), cmp);
    int totalValue = 0;
    // check each items ki entire item lelu ya fraction lu
    for (int i = 0; i < n; i++)
    {
        pair<int, int> item = data[i];
        int itemValue = item.first;
        int itemWeight = item.second;

        // entire inclusion
        if (itemWeight <= capacity)
        {
            // add kardo value ko
            totalValue += itemValue;
            // update knapsack capacity
            capacity -= itemWeight;
        }
        else
        {
            // fractional inclusion
            // add fraction value
            double ratio = itemValue / (double)itemWeight;
            int valueToAdd = ratio * capacity;
            totalValue += valueToAdd;

            // update capacity
            capacity = 0;
        }
    }

    cout << "ans : " << totalValue << endl;

    return 0;
}
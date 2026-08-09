#include <bits/stdc++.h>
using namespace std;

int getIthBit(int n, int i)
{
    int mask = 1 << i;
    int ans = n & mask;
    return ans == 0 ? 0 : 1;
}

void setithBit(int n, int i)
{
    int mask = 1 << i;
    int ans = n | mask;
    cout << "after setting bit : " << ans << endl;
}

void clearithBit(int &n, int i)
{
    int mask = ~(1 << i);
    // int ans = n & mask;
    // cout << "after clearing ith bit : " << ans << endl;
    n = n & mask;
}

void updateithBit(int &n, int i, int target)
{
    clearithBit(n, i);
    int mask = target << i;
    n = n | mask;
    cout << "after updating number's ith bit to target : " << n << endl;
}

void clearLastIBits(int n, int i)
{
    int mask = (-1 << i);
    n = n & mask;
    cout << "after clearing last i bits : " << n << endl;
}

bool checkPowerOfTwo(int n)
{
    if ((n & (n - 1)) == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int countSetBits(int n)
{
    int count = 0;
    while (n != 0)
    {
        int lastBit = n & 1;
        if (lastBit)
        {
            count++;
        }
        n = n >> 1;
    }
    return count;
}

int countSetBitsFast(int n)
{
    int count = 0;
    while (n != 0)
    {
        // remove last set bit
        n = (n & (n - 1));
        count++;
    }
    return count;
}

void clearBitsInRange(int n, int i, int j)
{
    int mask1 = (-1 << (i + 1));
    int mask2 = (1 << j) - 1;
    int mask = mask1 | mask2;
    n = n & mask;
    cout << "ans : " << n;
}

void getSubsequences(string str)
{
    vector<string> ans;
    int n = str.length();

    for (int num = 0; num < (1 << n); num++)
    {
        string temp = "";
        // we will create subsequence string in this temp str
        for (int i = 0; i < n; i++)
        {
            char ch = str[i];
            if (num & (1 << i))
            {
                temp.push_back(ch);
            }
        }

        if (temp.length() >= 0)
        {
            ans.push_back(temp);
        }
    }
    cout << "count of subsequences : " << ans.size() << endl;
    for (auto i : ans)
    {
        cout << i << endl;
    }
}

int main()
{
    //     int ans = getIthBit(10, -1);
    //     cout << ans << endl;

    // setithBit(10, 2);

    // int n = 10;
    // clearithBit(n, 1);

    // int n = 10;
    // updateithBit(n, 1, 0);

    // clearLastIBits(7, 2);

    // cout << checkPowerOfTwo(16) << endl;

    // cout << "number of set bit : " << countSetBits(15) << endl;

    // clearBitsInRange(15, 2, 1);

    string str = "abc";
    getSubsequences(str);

    return 0;
}
// sum of min and max element of all subarray of size k
#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int sumofminmaxofallwindowofsizek(vector<int> &nums, int k)
{

    int ans = 0;
    deque<int> dq1, dq2;

    // process first window of k size
    for (int i = 0; i < k; i++)
    {
        // pehle smaller elements ko remove kardo
        // aa question ma aapde smaller ne pachal thi remove karine je moto element hoi ene j pachal add karie chhie etle ahiya dq1.back() check karyu
        while (!dq1.empty() && nums[i] >= nums[dq1.back()])
        {
            dq1.pop_back();
        }

        // bada element remove kardo
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }

        // add index, so that we can check out of window element for next window
        dq1.push_back(i);
        dq2.push_back(i);
    }

    ans += nums[dq1.front()] + nums[dq2.front()];

    // process remaining window
    for (int i = k; i < nums.size(); i++)
    {
        // out of window element ko remove kardo
        if ((!dq1.empty()) && (i - dq1.front() >= k))
        {
            dq1.pop_front();
        }
        if ((!dq2.empty()) && (i - dq2.front() >= k))
        {
            dq2.pop_front();
        }

        // hve fari current ele mate smaller elements ne remove kari do
        // aa question ma aapde smaller ne pachal thi remove karine je moto element hoi ene j pachal add karie chhie etle ahiya dq1.back() check karyu
        while (!dq1.empty() && nums[i] >= nums[dq1.back()])
        {
            dq1.pop_back();
        }
        while (!dq2.empty() && nums[i] <= nums[dq2.back()])
        {
            dq2.pop_back();
        }

        // add index, so that we can check out of window element for next window
        dq1.push_back(i);
        dq2.push_back(i);

        // curr window mate ans store karo
        ans += nums[dq1.front()] + nums[dq2.front()];
    }

    return ans;
}

int main()
{

    vector<int> v{2, 5, -1, 7, -3, -1, -2};
    int k = 4;
    cout << sumofminmaxofallwindowofsizek(v, k) << endl;

    return 0;
}
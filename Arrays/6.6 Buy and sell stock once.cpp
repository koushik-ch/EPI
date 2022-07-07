#include <bits/stdc++.h>
using namespace std;

void buyAndSell(vector<int> &nums)
{
    int minSoFar = nums[0];
    int ans = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        ans = max(ans, nums[i] - minSoFar);
        minSoFar = min(minSoFar, nums[i]);
    }

    cout << "Max profit: " << ans << endl;
}

// Variant: To find the maximum subarray with equal values
void findMaxEqualSubarray(vector<int> &nums)
{
    int prev = nums[0];
    int maxCount = 0, currCount = 0;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == prev)
        {
            currCount++;
        }
        else
        {
            maxCount = max(maxCount, currCount);
            currCount = 1;
            prev = nums[i];
        }
    }
    cout << "Max count: " << maxCount << endl;
}

int main()
{
}
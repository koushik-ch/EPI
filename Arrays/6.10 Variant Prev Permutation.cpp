#include <bits/stdc++.h>
using namespace std;

// Reverse as Next Permutation

void getNextPermutation(vector<int> &nums)
{
    int breakPoint = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] > nums[i + 1])
        {
            breakPoint = i;
            break;
        }
    }

    if (breakPoint == -1)
    {
        reverse(nums.begin(), nums.end());
        for (int i = 0; i < n; i++)
            cout << nums[i] << " ";
        return;
    }

    for (int i = n - 1; i > breakPoint; i--)
    {
        if (nums[i] < nums[breakPoint])
        {
            swap(nums[i], nums[breakPoint]);
            break;
        }
    }
    reverse(nums.begin() + breakPoint + 1, nums.end());

    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
}

int main()
{
    vector<int> nums = {4, 1, 2, 3};
    getNextPermutation(nums);
    return 0;
}

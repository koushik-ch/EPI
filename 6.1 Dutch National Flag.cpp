
#include <bits/stdc++.h>

using namespace std;

void brute(vector<int> &nums, int pivot)
{
    // TC->O(n^2)

    // WE ARRANGE ALL THE ELEMENTS LESS THAN THE PIVOT BEFORE THE PIVOT
    for (int i = 0; i < nums.size(); i++)
    {
        for (int j = i + 1; j < nums.size(); j++)
        {
            if (nums[j] < pivot)
            {
                swap(nums[j], nums[i]);
                break;
            }
        }
    }

    // WE ARRANGE ALL THE ELEMENTS GREATER THAN THE PIVOT AFTER THE PIVOT
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            if (nums[j] > pivot)
            {
                swap(nums[j], nums[i]);
                break;
            }
        }
    }
    for (auto num : nums)
        cout << " " << num;
}

void better(vector<int> &nums, int pivot)
{
    // TC->O(n)

    // In the brute force, we were repeatedly checking for the smaller/greater element right from
    // the beginning of the array which causes an extra iteration each time...here we avoid that using pointers
    int smallest = 0, greatest = nums.size() - 1;

    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] < pivot)
            swap(nums[i], nums[smallest++]);
    }

    for (int i = nums.size() - 1; i >= 0; i--)
    {
        if (nums[i] > pivot)
            swap(nums[i], nums[greatest--]);
    }

    for (auto num : nums)
        cout << " " << num;
}

void optimal(vector<int> &nums, int pivot)
{
    // TC->O(N)

    int lowPtr = 0, highPtr = nums.size() - 1, i = 0;

    while (i <= highPtr)
    {
        if (nums[i] < pivot)
        {
            swap(nums[i++], nums[lowPtr++]);
        }
        else if (nums[i] > pivot)
        {
            swap(nums[i], nums[highPtr--]);
        }
        else
            i++;
    }

    for (auto num : nums)
        cout << " " << num;
}

int main()
{
    vector<int> nums = {9, 43, 6, 13, 64, 263};

    optimal(nums, 6);
}

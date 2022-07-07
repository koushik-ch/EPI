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

    /*    The time complexity is0(n) and the space complexity is0(1).
        The algorithm we now present is similar to the one sketched above. The main
        difference is that it performs classification into elements less than, equal to, and
        greater than the pivot in a single pass. This reduces runtime, at the cost of a trickier
        implementation. We do this by maintaining four subarrays: bottom (elements less
        than pivot), middle (elements equal to pivot), unclassified, and top (elements greater
        than pivot). Initially, all elements are in unclassified. We iterate through elements in
        unclassified, and move elements into one of bottom, middle, and top groups according
        to the relative order between the incoming unclassified element and the pivot.
        Asa concrete example,suppose thearray iscurrentlyA = (-3,0,-1,1,1, ?,?,?,4, 2),
        where the pivot is1and ? denotes unclassified elements. There are three possibilities
        for the first unclassified element, A[5].

        • A[5] is less than the pivot, e.g., A[5] = -5. We exchange it with the first 1, i.e.,
        the new array is(-3,0,-1,-5,1,1, ?,?,4, 2).
        • A[5] is equal to the pivot, i.e., A[5] = 1. We do not need to move it, we just ad¬
        vance to the next unclassified element, i.e., the array is(-3,0,-1,1,1,1, ?, ?, 4, 2).
        • A[5] is greater than the pivot, e.g., A[5] = 3. We exchange it with the last
        unclassified element, i.e., the new array is(-3,0,-1,1,1, ?, ?,3,4, 2).

    */

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

/* Variants:


*/

int main()
{
    vector<int> nums = {9, 43, 6, 13, 64, 263};

    optimal(nums, 6);
}

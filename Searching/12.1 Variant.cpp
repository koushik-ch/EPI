#include <bits/stdc++.h>

using namespace std;

/*
    Write a program which takes a sorted array A of integers, and an integer k,
    and returnsthe interval enclosing k,i.e., the pair of integers L and U such that L isthe
    first occurrence of k in A and U is the last occurrence of k in A. If k does not appear
    in A, return [-1,-1], For example if A = (1,2,2,4,4,4,7,11,11,13) and k = 11, you
    should return [7,8]

*/
vector<int> findInterval(vector<int> &nums, int k)
{
    int n = nums.size();
    int l = 0, r = n - 1;
    vector<int> ans(2, -1);

    // To find the first occurrence of k in nums
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] >= k)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << nums[l] << endl;
    if (nums[l] == k)
        ans[0] = l;

    // To find the last occurrence of k in nums
    r = n - 1;
    while (l <= r)
    {
        int mid = l + (r - l) / 2;
        if (nums[mid] <= k)
            l = mid + 1;
        else
            r = mid - 1;
    }
    cout << nums[r] << endl;
    if (nums[r] == k)
        ans[1] = r;
    return ans;
}

int main()
{
    vector<int> nums = {1, 2, 2, 4, 4, 4, 7, 11, 11, 13};
    int k = 11;
    vector<int> ans = findInterval(nums, k);
    cout << ans[0] << " " << ans[1] << endl;
    return 0;
}
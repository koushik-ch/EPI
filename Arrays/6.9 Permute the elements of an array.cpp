#include <bits/stdc++.h>
using namespace std;

void findNextPerumte(vector<int> &nums, vector<int> &perm)
{
    int n = nums.size();

    for (int i = 0; i < n; i++)
    {
        int next = i;
        while (perm[next] >= 0)
        {
            swap(nums[i], nums[next]);
            int temp = perm[next];
            perm[next] -= n;
            next = temp;
        }
    }
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
}

int main()
{
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    vector<int> perm = {2, 3, 1, 4, 5, 6};
    findNextPerumte(nums, perm);
    return 0;
}
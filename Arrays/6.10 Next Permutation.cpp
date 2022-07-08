#include <bits/stdc++.h>
using namespace std;

/*
    The key insight isthat we want to increase the permutation by aslittle as possible.
    The loose analogy ishowa car'sodometerincrements; thedifference isthat wecannot
    change values, only reorder them. We will use the permutation (6,2,1,5,4,3,0} to
    develop this approach.
    Specifically, westartfrom the right,and look at the longest decreasingsuffix,which
    is (5,4,3,0} for our example. We cannot get the next permutation just by modifying
    thissuffix,since it is already the maximum it can be.
    Instead we look at the entry e that appearsjust before the longest decreasing suffix,
    which is1in this case. (If there's no such element, i.e., the longest decreasing suffix
    is the entire permutation, the permutation must be (n — 1, n — 2,...,2,1,0), for which
    there is no next permutation.)
    Observe that e must be less than some entries in the suffix (since the entry imme¬
    diately after e is greater than e). Intuitively, we should swap e with the smallest entry
    s in the suffix which islarger than e so as to minimize the change to the prefix (which
    is defined to be the part of the sequence that appears before the suffix).

    For our example, e is 1 and s is 3. Swapping s and e results in (6, 2,3,5,4,1,0).
    We are not done yet—the new prefix is the smallest possible for all permutations
    greater than the initial permutation, but the new suffix may not be the smallest. We
    can get the smallest suffix by sorting the entries in the suffix from smallest to largest.
    For our working example, this yields the suffix (0,1,4,5).
    As an optimization, it is not necessary to call a full blown sorting algorithm on
    suffix. Since the suffix was initially decreasing, and after replacing s by e it remains
    decreasing, reversing the suffix has the effect of sorting it from smallest to largest.
    The general algorithm for computing the next permutation is asfollows:
    (1.) Find k such that p[k] < p[k + 1] and entries after index k appear in decreasing
    order.
    (2.) Find the smallest p[l] such that p[l] > p[k] (such an / must exist since p[k] <
    p[k+l]).
    (3.) Swap p[l] and p[k] (note that the sequence after position k remainsin decreasing
    order).
    (4.) Reverse the sequence after position k
*/
void getNextPermutation(vector<int> &nums)
{
    int breakPoint = -1;
    int n = nums.size();
    for (int i = n - 2; i >= 0; i--)
    {
        if (nums[i] < nums[i + 1])
        {
            breakPoint = i;
            break;
        }
    }

    if (breakPoint == -1)
    {
        reverse(nums.begin(), nums.end());
        return;
    }

    for (int i = n - 1; i > breakPoint; i--)
    {
        if (nums[i] > nums[breakPoint])
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
    vector<int> nums = {1, 2, 3, 4, 5, 6};
    getNextPermutation(nums);
    return 0;
}

#include <bits/stdc++.h>
using namespace std;
// TRY THE SECOND VARIANT

/*
    BRUTE FORCE SOLUTION
    Let A be the array and n its length. If we allow ourselves0(n) additional
    space, we can solve the problem by iterating through A and recording values that
    have not appeared previously into a hash table. (The hash table is used to determine
    if a value is new.) New values are also written to a list. The list is then copied back
    into A.
    Time Complexity: O(n)
    Space Complexity: O(n)

    OPTIMAL SOLUTION
    The intuition behind achieving a better time complexity isto reduce the amount of
    shifting. Since the array issorted, repeated elements must appear one-after-another,
    so we do not need an auxiliary data structure to check if an element has appeared
    already. We move just one element, rather than an entire subarray, and ensure that
    we move it just once.
    For the given example, (2,3,5,5,7,11,11,11,13), when processing the A[3], since
    we already have a 5 (which we know by comparing A[3] with A[2]), we advance to
    A[4], Since thisis a new value, we move it to the first vacant entry, namely A[3]. Now
    the array is (2,3,5,7,7,11,11,11,13), and the first vacant entry is A[4]. We continue
    from A[5],
    Time complexity: O(n)
    Space complexity: O(1)

*/

void remove(vector<int> &nums)
{
    int prevNum = 0, nextFreeSlot = 1;
    for (int j = 1; j < nums.size(); j++)
    {
        if (nums[prevNum] != nums[j])
        {
            swap(nums[nextFreeSlot], nums[j]);
            prevNum++;
            nextFreeSlot++;
        }
    }

    for (auto num : nums)
        cout << num << " ";
}

// Variant
/*
    Implement a function which takes asinput an array and a key and updates
    thearrayso that alloccurrencesof the input key have been removed and the remaining
    elements have been shifted left to fill the emptied indices. Return the number of
    remaining elements. There are no requirements as to the values stored beyond the
    last valid element
*/
void removeOccurencesOfKey(vector<int> &nums, int key)
{
    // Find the first index of the key
    int firstIndex;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == key)
        {
            firstIndex = i;
            break;
        }
    }
    /*
        Take the key's first index as the next free slot and move the elements to the next
        free slot whenever we find a number not equal to the key. we use the first index of the
        key as the next free slot unlike the original problem where we use the next index of the
        key as the next free slot as we should use one occurence of each number there whereas here
        we do not.
    */
    int nextFreeSlot = firstIndex;

    for (int i = firstIndex; i < nums.size(); i++)
    {
        if (nums[i] != key)
        {
            swap(nums[nextFreeSlot], nums[i]);
            nextFreeSlot++;
        }
    }
    for (auto num : nums)
        cout << num << " ";
}

int main()
{
    vector<int> nums = {1, 1, 3, 3, 3, 5, 5, 5, 7, 7, 7, 88};
    removeOccurencesOfKey(nums, 5);
    return 0;
}

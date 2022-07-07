#include <bits/stdc++.h>

using namespace std;

/*
    The quicksort algorithmforsorting arrays proceedsrecursively—itselects an element
    (the "pivot"),reordersthe array to make all the elementslessthan or equal to the pivot
    appear first, followed by all the elements greater than the pivot. The two subarrays
    are then sorted recursively.
    Implemented naively, quicksort haslarge run times and deep function call stacks
    on arrays with many duplicates because the subarrays may differ greatly in size. One
    solution is to reorder the array so that all elements less than the pivot appear first,
    followed by elements equal to the pivot,followed by elements greater than the pivot.
    This is known as Dutch national flag partitioning, because the Dutch national flag
    consists of three horizontal bands, each in a different color.
    As an example, assuming that black precedes white and white precedes gray,
    Figure 6.1(b) on the facing page is a valid partitioning for Figure 6.1(a) on the next
    page. If gray precedes black and black precedes white, Figure 6.1(c) on the facing
    page is a valid partitioning for Figure 6.1(a) on the next page.
    Generalizing,suppose A = (0,l,2,0,2,l,l),andthepivotindexis3. Then A[3] = 0,
    so (0,0,1, 2, 2,1,1) is a valid partitioning. For the same array, if the pivot index is 2,
    then A[2] = 2, so the arrays(0,1,0,1,1, 2, 2) as well as langle0,0,1,1,1, 2, 2) are valid
    partitionings.

*/
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

    Given an array A of n objects with keys that takes one of four values, reorder
    the arrayso that allobjectsthat have the same key appear together. Use0(1)additional
    space and 0(n) time.

    Soln: We can use the same idea as in the optimal solution. We do the the operation twice,
    first to sort the elements based on the 2nd largest element and then based on the 3rd
    ie, {0,2,1,2,0,3,3,1,3,2}
        1)Arrange with '1' as the pivot -> {0 0 1 1 3 3 2 3 2 2}
        2)Now arrange with '2' as the pivot -> { 0 0 1 1 2 2 2 3 3 3}

*/

int main()
{
    vector<int> nums = {9, 43, 6, 13, 64, 263};

    optimal(nums, 6);
}

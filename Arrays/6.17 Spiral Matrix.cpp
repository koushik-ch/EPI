#include <bits/stdc++.h>
using namespace std;

/*

    It is natural to solve this problem starting from the outside, and working
    to the center. The naive approach begins by adding the first row, which consists of n
    elements. Next we add the n-1remaining elements of the last column, then the n-1
    remaining elements of the last row, and then the n-2 remaining elements of the first
    column. The lack of uniformity makesit hard to get the code right.
    Here is a uniform way of adding the boundary. Add the first n-1elements of the
    first row. Then add the first n — 1elements of the last column. Then add the last n-1
    elements of the last row in reverse order. Finally, add the last n— 1 elements of the
    first column in reverse order.
    After this, we are left with the problem of adding the elements of an (n-2) X (n-2)
    2D array in spiral order. This leads to an iterative algorithm that adds the outermost
    elements of n X n,(n - 2) X (n - 2),(« - 4) X (n - 4),... 2D arrays. Note that a matrix
    of odd dimension has a comer-case, namely when we reach its center.
    As an example, for the3x3array in Figure 6.3(a) on the previous page, we would
    add 1,2 (first two elements of the first row), then 3,6 (first two elements of the last
    column), then 9,8 (last two elements of the last row), then 7,4 (last two elements of
    the first column). We are now left with the lxl array, whose sole element is5. After
    processing it, all elements are processed.
    For the 4x4array in Figure 6.3(b) on the preceding page,we would add 1,2,3(first
    three elements of the first row), then 4,8,12 (first three elements of the last column),
    then 16,15,14 (last three elements of the last row), then 13,9,5 (last three elements of
    the first column). We are now left with a 2 X 2 matrix, which we processsimilarly in
    the order 6, 7,11,10, after which all elements are processed.

*/
void spiralMatrix(vector<vector<int>> &mat, vector<int> &spiral, int offset)
{
    for (int i = offset; i < mat.size() - offset - 1; i++)
    {
        spiral.push_back(mat[offset][i]);
    }

    for (int i = offset; i < mat.size() - offset - 1; i++)
    {
        spiral.push_back(mat[i][mat.size() - 1 - offset]);
    }

    for (int i = mat.size() - 1 - offset; i > offset; i--)
    {
        spiral.push_back(mat[mat.size() - 1 - offset][i]);
    }
    for (int i = mat.size() - 1 - offset; i > offset; i--)
    {
        spiral.push_back(mat[i][offset]);
    }
}

int main()
{

    vector<vector<int>> mat = {{1, 2, 3, 4, 5},
                               {6, 7, 8, 9, 10},
                               {11, 12, 13, 14, 15},
                               {16, 17, 18, 19, 20},
                               {21, 22, 23, 24, 25}};
    vector<int> spiral;

    for (int offset = 0; offset < mat.size() / 2; offset++)
    {
        spiralMatrix(mat, spiral, offset);
    }
    if (mat.size() % 2 == 1)
    {
        spiral.push_back(mat[mat.size() / 2][mat.size() / 2]);
    }
    for (int i = 0; i < spiral.size(); i++)
    {
        cout << spiral[i] << " ";
    }
    return 0;
}
/*

    You are given two strings start and target, both of length n. Each string consists only of the characters 'L', 'R', and '_' where:

    The characters 'L' and 'R' represent pieces, where a piece 'L' can move to the left only if there is a blank space directly to its left, and a piece 'R' can move to the right only if there is a blank space directly to its right.
    The character '_' represents a blank space that can be occupied by any of the 'L' or 'R' pieces.
    Return true if it is possible to obtain the string target by moving the pieces of the string start any number of times. Otherwise, return false.



    Example 1:

    Input: start = "_L__R__R_", target = "L______RR"
    Output: true
    Explanation: We can obtain the string target from start by doing the following moves:
    - Move the first piece one step to the left, start becomes equal to "L___R__R_".
    - Move the last piece one step to the right, start becomes equal to "L___R___R".
    - Move the second piece three steps to the right, start becomes equal to "L______RR".
    Since it is possible to get the string target from start, we return true.
    Example 2:

    Input: start = "R_L_", target = "__LR"
    Output: false

*/

class Solution
{
public:
    bool canChange(string s, string t)
    {

        queue<pair<char, int>> sq;
        queue<pair<char, int>> tq;

        int n = s.length();

        for (int i = 0; i < s.length(); i++)
        {
            if (s[i] != '_')
                sq.push({s[i], i});
        }

        for (int i = 0; i < t.length(); i++)
        {

            if (t[i] != '_')
                tq.push({t[i], i});
        }

        if (sq.size() != tq.size())
            return false;

        while (sq.size())
        {
            pair<char, int> sp, tp;
            sp = sq.front();
            tp = tq.front();

            sq.pop();
            tq.pop();

            if (sp.first != tp.first)
                return false;

            if (sp.first == 'L' && tp.second > sp.second)
                return false;
            if (sp.first == 'R' && tp.second < sp.second)
                return false;
        }
        return true;
    }
};
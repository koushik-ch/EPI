#include <bits/stdc++.h>
using namespace std;

// We use the elementary school multiplyer algorithm to multiply two numbers.

void multiply(vector<int> &num1, vector<int> &num2)
{
    int m = num1.size(), n = num2.size();
    vector<int> result(m + n, 0);
    for (int i = m - 1; i >= 0; i--)
    {
        for (int j = n - 1; j >= 0; j--)
        {
            int sum = result[i + j + 1] + num1[i] * num2[j];
            result[i + j + 1] = sum % 10;
            result[i + j] += sum / 10;
        }
    }
    int ptr = 0;
    while (result[ptr] == 0)
        ptr++;

    for (int i = ptr; i < result.size(); i++)
        cout << result[i];
}

int main()
{
    vector<int> num1 = {2, 6, 4, 7, 8, 3, 7};
    vector<int> num2 = {1, 2, 6};
    multiply(num1, num2);
    return 0;
}
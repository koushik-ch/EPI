#include <bits/stdc++.h>
using namespace std;

int stringToInt(string s)
{
    int num = 0;

    for (int i = 0; i < s.length(); i++)
    {
        num *= 10;
        num += (s[i] - '0');
    }
    return num;
}

string intToString(int n)
{
    int num = n;
    string s;

    while (num)
    {
        s += (num % 10) + '0';
        num /= 10;
    }
    reverse(s.begin(), s.end());
    return s;
}

int main()
{
    string s = "12345";
    cout << stringToInt(s) << endl;
    cout << intToString(stringToInt(s)) << endl;
}
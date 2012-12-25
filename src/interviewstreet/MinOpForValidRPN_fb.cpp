/**@file
 * Copyright (C), 1998-2012, Tencent Technology Company Limited
 * 
 * @author	bensonzhang <bensonzhang@tencent.com>
 * @date	2012-12-23
 */

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const char X = 'x';
const char OP = '*';

bool IsX(char c)
{
    return c == X;
}

int MinOpForValidRPN(const string& s)
{
    if (s.size() == 0) return 0;

    int n = s.size();
    vector<vector<int> > d(n, vector<int>(n + 1, 0));

    for (int i = 0; i < n; ++i)
    {
        d[i][0] = 0;
        if (IsX(s[i])) d[i][1] = 0;
        else d[i][1] = 1;
        if (i + 1 < n)
        {
            if (!IsX(s[i]) && !IsX(s[i + 1]))
            {
                d[i][2] = 2;
            }
            else
            {
                d[i][2] = 1;
            }
        }
    }
    for (int len = 3; len <= n; ++len)
    {
        for (int i = 0; i + len - 1 < n; ++i)
        {
            int end = i + len - 1;
            int ex = IsX(s[end]) ? 1 : 0;
            int best = d[i][len - 1] + 1;
            for (int j = 1; j <= len - 2; ++j)
            {
                best = min(best, d[i][j] + d[i + j][len - 1 - j] + ex);
            }
            d[i][len] = best;
        }
    }
    return d[0][n];
}

int main()
{
	int ncases;
	cin >> ncases;
	while (--ncases >= 0)
	{
	    string line;
	    cin >> line;
	    cout << MinOpForValidRPN(line) << endl;
	}

    return 0;
}

// https://leetcode.com/problems/maximum-length-of-pair-chain/description/

#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<vector<int>> dp;
    int solve(vector<vector<int>> &pairs, int i, int p)
    {

        if (i >= pairs.size())
        {
            return 0;
        }
        int prev = p + 1;

        if (p != -1 && dp[i][prev] != -1)
        {
            return dp[i][prev];
        }

        int pick = 0;
        if (p == -1 || pairs[p][1] < pairs[i][0])
        {
            pick = 1 + solve(pairs, i + 1, i);
        }
        int notpick = solve(pairs, i + 1, p);

        return dp[i][prev] = max(pick, notpick);
    }

    int findLongestChain(vector<vector<int>> &pairs)
    {
        sort(pairs.begin(), pairs.end());

        dp = vector<vector<int>>(pairs.size(), vector<int>(pairs.size() + 1, -1));

        return solve(pairs, 0, -1);
    }
};
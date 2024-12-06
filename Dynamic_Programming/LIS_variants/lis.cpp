https : // leetcode.com/problems/longest-increasing-subsequence/description/

#include <bits/stdc++.h>
        using namespace std;

class Solution
{
public:
    //  int dp[2501][2501];

    // int solve(int i, vector<int>&nums, int n){

    //     if(i>=nums.size())return 0;

    //     // When n is -1, we'll use 0 index for dp array
    //     int prev = n + 1;  // Added this line to handle -1 case

    //     if(n!=-1 && dp[i][prev]!=-1){
    //         return dp[i][prev];
    //     }

    //     int take=0;

    //     if(n==-1 || nums[i]>nums[n]){
    //        take = 1+ solve(i+1,nums,i);
    //     }
    //     int nottake= solve(i+1,nums,n);

    //     return dp[i][prev]=max(take,nottake);  // Store with adjusted index
    // }

    int lengthOfLIS(vector<int> &nums)
    {
        // memset(dp,-1,sizeof(dp));
        // return solve(0,nums,-1);

        // Tabulation

        int maxlen = 1;
        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[j] < nums[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxlen = max(dp[i], maxlen);
                }
            }
        }
        return maxlen;
    }
};
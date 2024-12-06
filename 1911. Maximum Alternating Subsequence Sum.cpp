// https://leetcode.com/problems/maximum-alternating-subsequence-sum/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // typedef long long ll;
    // ll dp[100001][2];

    // ll solve(int i,vector<int>&nums, bool iseven){

    //     if(i>=nums.size()){
    //         return 0;
    //     }

    //     if(dp[i][iseven]!=-1){
    //         return dp[i][iseven];
    //     }

    //     ll val= nums[i];
    //     ll skip= solve(i+1,nums,iseven);

    //     if(iseven==false){
    //         val=-val;
    //     }
    //     ll take= solve(i+1,nums,!iseven)+val;

    //     return dp[i][iseven]=max(skip,take);

    // }

    long long maxAlternatingSum(vector<int> &nums)
    {
        // MEMO
        //  memset(dp,-1,sizeof(dp));
        //  return solve(0,nums,true);

        int n = nums.size();
        vector<vector<long long>> t(n + 1, vector<long long>(2, 0)); // even=0 odd=1

        for (int i = 1; i < n + 1 /* exploring till last in dp array*/; i++)
        {
            // If picking this will make it even-> odd+1=even, then we will take value of odd
            //  Also -nums[i] because even means lessing up the value
            t[i][0] = max(t[i - 1][1] - nums[i - 1], t[i - 1][0]); // Max of pick non pick in even, non pick is the last index value only in dp
            // If picking for odd -> even+1= odd

            t[i][1] = max(t[i - 1][0] + nums[i - 1], t[i - 1][1]);
        }

        return max(t[n][0], t[n][1]);
    }
};
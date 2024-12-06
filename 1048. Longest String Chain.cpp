// https://leetcode.com/problems/longest-string-chain/

class Solution
{
public:
    int n;

    bool predecessor(string &prev, string &curr)
    {
        int M = prev.length();
        int N = curr.length();

        if (M >= N || N - M != 1)
            return false;

        int i = 0, j = 0;
        while (i < M && j < N)
        {
            if (prev[i] == curr[j])
            {
                i++;
            }
            j++;
        }
        return i == M;
    }

    static bool myFunction(string &s1, string &s2)
    {
        return s1.length() < s2.length();
    }

    int longestStrChain(vector<string> &nums)
    {

        int n = nums.size();
        sort(nums.begin(), nums.end(), myFunction);
        int maxlen = 1;
        vector<int> dp(nums.size(), 1);

        for (int i = 0; i < nums.size(); i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (predecessor(nums[j], nums[i]))
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxlen = max(dp[i], maxlen);
                }
            }
        }
        return maxlen;
    }
};

1420. Build Array Where You Can Find The Maximum Exactly K Comparisons
    https : // leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/description/

            class Solution
{
public:
    int dp[51][51][101];

    int N, M, K;
    int MOD = 1e9 + 7;

    int solve(int i, int cost, int maxtillnow)
    {

        if (i == N)
        {
            if (cost == K)
            {
                return 1;
            }
            return 0;
        }

        if (dp[i][cost][maxtillnow] != -1)
        {
            return dp[i][cost][maxtillnow];
        }

        int result = 0;
        for (int j = 1; j <= M; j++)
        {

            if (j > maxtillnow)
            {
                result = (result + solve(i + 1, cost + 1, j)) % MOD;
            }
            else
            {
                result = (result + solve(i + 1, cost, maxtillnow)) % MOD;
            }
        }

        return dp[i][cost][maxtillnow] = result % MOD;
    }

    int numOfArrays(int n, int m, int k)
    {
        N = n;
        K = k;
        M = m;
        memset(dp, -1, sizeof(dp));
        return solve(0, 0, 0);
    }
};
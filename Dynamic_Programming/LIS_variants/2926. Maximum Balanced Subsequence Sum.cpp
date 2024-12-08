#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxBalancedSubsequenceSum(vector<int> &nums)
    {
        int n = nums.size();

        map<int, long long> mp; // nums[i]-i, sum

        long long result = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            auto it = mp.upper_bound(nums[i] - i);

            long long sum = nums[i];

            if (it != mp.begin())
            {
                it--;
                sum += (*it).second;
            }

            mp[nums[i] - i] = max(mp[nums[i] - i], sum);

            // Finding and deleting elements below than smaller value with smaller sum
            it = mp.upper_bound(nums[i] - i);

            while (it != mp.end() && it->second <= sum)
            {
                mp.erase(it++);
            }
            result = max(result, sum);
        }

        return result;
    }
};

/*Dp MEMO and Tabulation won't work because it has n square complexity

But Here upper_bound makes it nlogn (MAIN CRUX)


Key Takeaways


-> Map beacuse efficient storing of elements and easy accessing (nums[i]-i, sum)

*/

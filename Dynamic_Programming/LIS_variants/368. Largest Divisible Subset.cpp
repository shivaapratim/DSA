#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> largestDivisibleSubset(vector<int> &nums)
    {
        sort(begin(nums), end(nums));

        int n = nums.size();
        vector<int> t(n, 1);

        vector<int> prev_idx(n, -1);
        int last_chosen_index = 0;
        int maxL = 1;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (nums[i] % nums[j] == 0)
                {
                    if (t[i] < t[j] + 1)
                    {
                        t[i] = t[j] + 1;
                        prev_idx[i] = j;
                    }

                    if (t[i] > maxL)
                    {
                        maxL = t[i];
                        last_chosen_index = i;
                    }
                }
            }
        }

        vector<int> result;
        while (last_chosen_index >= 0)
        {
            result.push_back(nums[last_chosen_index]);
            last_chosen_index = prev_idx[last_chosen_index];
        }

        return result;
    }
};

//     In this a 2 for loop and sorted finding the elements wont work because it will skip some numbers

// Actually all the numbers in the subset should be %==0 of each other in the given condition

// So we use pick and non pick stratergy but it will also fail for 2 end cases that is where we use tabulation

// And we recall the concept of LIS

// Which is in tabulation , taking one previous and maxing the value of length if we find that t[j]+1 is greater

//  t[i] = t[j]+1;
//  prev_idx[i] = j;

//  DP-> (CRUX-> Checking with the back element of previous array)

//  Some new steps because we need to store the subsets tooo then we at last take from the last and populate result array

//  Last->[-1,-1,-1, 2,4,8,]... Example
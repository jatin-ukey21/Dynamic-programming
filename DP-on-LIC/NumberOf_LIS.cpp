#include<bits/stdc++.h>
using namespace std;

/*
Given an integer array nums, return the number of longest increasing subsequences.

Notice that the sequence has to be strictly increasing.
*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        
        // dp[i] = length of longest increasing subsequence ending at index i
        // cnt[i] = number of such LIS ending at index i
        vector<int> dp(n, 1), cnt(n, 1);

        int maxi = -1; // to store length of the LIS

        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                // if nums[i] can extend the subsequence ending at prev
                if(nums[i] > nums[prev]) {
                    if(dp[prev] + 1 > dp[i]) {
                        // found a longer LIS ending at i
                        dp[i] = dp[prev] + 1;

                        // inherit the count from prev
                        cnt[i] = cnt[prev];
                    }
                    else if(dp[prev] + 1 == dp[i]) {
                        // found another LIS of the same length ending at i
                        cnt[i] += cnt[prev];
                    }
                }
            }
            maxi = max(maxi, dp[i]);
        }

        // accumulate all counts of LIS which are of maximum length
        int nos = 0;
        for(int i = 0; i < n; i++) {
            if(dp[i] == maxi)
                nos += cnt[i];
        }

        return nos;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1,3,5,4,7};
    cout << "Number of Longest Increasing Subsequences: " << sol.findNumberOfLIS(nums) << endl;
    // Output: Number of Longest Increasing Subsequences: 2
    // Explanation: The two longest increasing subsequences are [1,3,4,7] and [1,3,5,7].
    
    return 0;
}
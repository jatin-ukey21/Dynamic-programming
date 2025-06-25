#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Tabulation but different approach
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 1);

        int maxi = 1;
        for(int ind = 0; ind  < n; ind++){
            //ind - 1 -> we have to check elements before nums[ind]
            for(int prev_ind = 0; prev_ind <= ind - 1; prev_ind++){
                if(nums[prev_ind] < nums[ind]){
                    dp[ind] = max(dp[prev_ind] + 1,dp[ind]);
                    maxi = max(maxi,dp[ind]);
                }
            }
        }

        return maxi;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};

    // Dry run for nums = {10, 9, 2, 5, 3, 7, 101, 18}
    // dp = [1, 1, 1, 1, 1, 1, 1, 1] initially
    // For ind = 0: nothing to compare, dp[0] = 1
    // For ind = 1: nums[0]=10 > nums[1]=9, so no update, dp[1]=1
    // For ind = 2: nums[0]=10 > nums[2]=2, nums[1]=9 > nums[2]=2, so no update, dp[2]=1
    // For ind = 3: nums[2]=2 < nums[3]=5, so dp[3]=max(1, dp[2]+1)=2
    // For ind = 4: nums[2]=2 < nums[4]=3, so dp[4]=max(1, dp[2]+1)=2
    //              nums[3]=5 > nums[4]=3, so no update
    // For ind = 5: nums[2]=2 < nums[5]=7, dp[5]=max(1, dp[2]+1)=2
    //              nums[3]=5 < nums[5]=7, dp[5]=max(2, dp[3]+1)=3
    //              nums[4]=3 < nums[5]=7, dp[5]=max(3, dp[4]+1)=3
    // For ind = 6: check all previous, max dp[6]=4 (from dp[5]+1)
    // For ind = 7: check all previous, max dp[7]=4 (from dp[5]+1)
    // Final dp: [1,1,1,2,2,3,4,4], so answer is 4

    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;  // Output: 4 (The LIS is [2, 3, 7, 101])
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //Memoization
    int f(int ind,int prev_ind,int n,vector<int>& nums,vector<vector<int>>& dp){
        if(ind == n) return 0;

        if(dp[ind][prev_ind + 1] != -1) return dp[ind][prev_ind + 1];

        //not take, 0 shows not taken so length will not increase
        int len = 0 + f(ind + 1,prev_ind,n,nums,dp);

        //take
        if(prev_ind == -1 || nums[ind] > nums[prev_ind]){
            // 1 shows number is considered so length is increased by 1
            len = max(len,1 + f(ind + 1,ind,n,nums,dp));
        }

        return dp[ind][prev_ind + 1] = len;
    }
    int lengthOfLIS(vector<int>& nums) {
        //ind - current index
        //prev_indx - previous
        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(n+1,-1));  //doing n + 1 for shifting the previous index by +1 to handle the '-1' index case

        return f(0,-1,n,nums,dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {10, 9, 2, 5, 3, 7, 101, 18};
    cout << "Length of Longest Increasing Subsequence: " << sol.lengthOfLIS(nums) << endl;  // Output: 4 (The LIS is [2, 3, 7, 101])
    return 0;
}
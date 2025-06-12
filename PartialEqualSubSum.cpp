// referring the subset sum problem by considering the half of the totalSum of the array and giving it to subset sum function
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //memoization, subset sum problem reffered here
     bool f(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
        if(target == 0) return true;
        if(ind == 0) return arr[0] == target;
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        //not take
        bool notTake = f(ind - 1, target,arr,dp);
        
        //take only if
        bool take = false;
        if(arr[ind] <= target) take = f(ind - 1,target - arr[ind],arr,dp);
        
        return dp[ind][target] = take || notTake;
        
    }
    bool canPartition(vector<int>& nums) {
        int totalSum  = 0;
        for(int num: nums) totalSum += num;

        if(totalSum%2 == 1) return false;

        int subsetSum = totalSum/2;

        int n = nums.size();
        vector<vector<int>> dp(n,vector<int>(subsetSum + 1,-1));

        return f(n - 1,subsetSum,nums,dp);
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 5, 11, 5};

    if (sol.canPartition(nums)) {
        cout << "The array can be partitioned into two subsets with equal sum." << endl;
    } else {
        cout << "The array cannot be partitioned into two subsets with equal sum." << endl;
    }

    return 0;
}
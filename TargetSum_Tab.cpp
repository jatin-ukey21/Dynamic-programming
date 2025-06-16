#include<bits/stdc++.h>
using namespace std;
/*
ou are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.

For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".
Return the number of different expressions that you can build, which evaluates to target.
*/

class Solution {
public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(target+1,0));
        
        //base cases
         /*
            We have two valid subsets:
            Pick nothing → sum = 0
            Pick the 0 → sum = 0
            */
        if(arr[0] == 0) dp[0][0] = 2; 
        else dp[0][0] = 1;
        
        //remember this line 
        if(arr[0] != 0 && arr[0] <= target){
            dp[0][arr[0]] = 1;
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int sum = 0; sum <= target; sum++){
                int notPick = dp[ind - 1][sum];
                
                int pick = 0;
                if(arr[ind] <= sum) pick = dp[ind - 1][sum - arr[ind]];
                
                dp[ind][sum] = pick + notPick;
            }
        }
        
        return dp[n-1][target];
    }
    int countPartitions(vector<int>& arr, int d) {
        int totalSum = accumulate(arr.begin(),arr.end(),0);
        if(totalSum - d < 0 || (totalSum-d)%2 == 1) return 0;
        int target = (totalSum-d)/2;
        return perfectSum(arr,target);
    }
    //code copied for partitons with given difference gfg problem
    int findTargetSumWays(vector<int>& nums, int target) {
        return countPartitions(nums,target);
    }
};

int main() {
    vector<int> nums = {1, 1, 1, 1, 1};
    int target = 3;

    Solution sol;
    cout << sol.findTargetSumWays(nums, target) << endl; // Output: 5
    return 0;
}
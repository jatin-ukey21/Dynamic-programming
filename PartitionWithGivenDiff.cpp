//pre-requisites: subset sum problem, dynamic programming
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int f(int ind,int target,vector<int>& arr,vector<vector<int>>& dp){
        //if(target == 0) return 1;
        if(ind == 0) {
            /*
            We have two valid subsets:
            Pick nothing → sum = 0
            Pick the 0 → sum = 0
            */
            if(target == 0 && arr[0] == 0) return 2;
            if(target == 0 || arr[0] == target) return 1;
            return 0;
        }
        
        if(dp[ind][target] != -1) return dp[ind][target];
        
        int notPick = f(ind - 1,target,arr,dp);
        
        int pick = 0;
        if(arr[ind] <= target) pick = f(ind - 1,target - arr[ind],arr,dp);
        
        return dp[ind][target] = pick + notPick;
    }
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
};

int main() {
    Solution sol;
    vector<int> arr = {1, 2, 3, 4, 5};
    int d = 1;
    cout << sol.countPartitions(arr, d) << endl; // Output the number of valid partitions
    return 0;
}
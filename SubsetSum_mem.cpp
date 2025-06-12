//Memoization approach to solve the subset sum problem
#include <bits/stdc++.h>
using namespace std;

// The Subset Sum Problem:
// Given a set of integers and a target sum, determine if there is a subset
// of the given set with a sum equal to the target value.
// This is a classic problem that can be solved using recursion, dynamic programming,
// or memoization techniques.

class Solution {
  public:
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
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n,vector<int>(sum + 1,-1));
        return f(n - 1,sum,arr,dp);
    }
};

int main() {
    Solution sol;
    vector<int> arr = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    
    if (sol.isSubsetSum(arr, sum)) {
        cout << "Found a subset with the given sum." << endl;
    } else {
        cout << "No subset with the given sum exists." << endl;
    }
    
    return 0;
}
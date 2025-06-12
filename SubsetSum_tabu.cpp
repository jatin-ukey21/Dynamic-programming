// tabulation method for subset sum problem
#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<bool>> dp(n,vector<bool>(sum + 1,false));
        
        //base case: all index with sum = 0 will always be true
        for(int i = 0;i<n; i++) dp[i][0] = true;
        
        //base case: "To make arr[0] as the target sum, I can only take the 0-th index element."
        if(arr[0] <= sum){
            dp[0][arr[0]] = true;
        }
        
        for(int ind = 1; ind < n; ind++){
            for(int target = 1; target <= sum; target++){
                //not take, result will be same as the previous row
                bool notTake = dp[ind - 1][target];
                
            // If we take the current element, subtract its value from the target and check the previous row
                bool take = false;
                if(arr[ind] <= target){
                    take = dp[ind - 1][target - arr[ind]];
                }
                
                dp[ind][target] = take || notTake;
            }
        }
        
        return dp[n-1][sum];
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
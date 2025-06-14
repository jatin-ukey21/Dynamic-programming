#include<bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int f(int ind,int W,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp){
        if(ind == 0){
            if(wt[0] <= W) return val[0];
            return 0;
        }
        if(dp[ind][W] != -1) return dp[ind][W];
        
        int notTake = 0 + f(ind - 1,W,val,wt,dp);
        
        int take = INT_MIN; //do not take it as 0
        if(wt[ind] <= W) take = val[ind] + f(ind - 1,W - wt[ind],val,wt,dp);
        
        return dp[ind][W] = max(take,notTake);
    }
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        
    int n = wt.size();

    // Initialize 1D DP array: dp[wi] = max value for weight capacity 'wi'
    // This will act like the "previous row" in the 2D DP version
    vector<int> prev(W + 1, 0);  

    // Base case initialization:
    // If only the 0th item is available, we can take it only if wt[0] <= wi
    // So we fill dp[wi] = val[0] for all capacities >= wt[0]
    for(int wi = wt[0]; wi <= W; wi++) {
        prev[wi] = val[0];
    }

    // Loop over remaining items
    for(int ind = 1; ind < n; ind++) {
        // IMPORTANT: Traverse weights **backward** from W to 0
        // So we don't overwrite results of smaller weights too early
        //i.e for updation of prev[wt], we don't need prev[wt-1]
        //therefore we are traversing from reverse and logically we are
        //updating prev[ind] to new value
        for(int wi = W; wi >= 0; wi--) {
            // Case 1: Do NOT take the current item
            int notTake = prev[wi];

            // Case 2: Take the current item (if it fits in the capacity)
            int take = INT_MIN;
            if(wt[ind] <= wi) {
                // Take current value and add optimal solution for remaining weight
                take = val[ind] + prev[wi - wt[ind]];
            }

            // Store the max of both choices
            prev[wi] = max(take, notTake);
        }
    }

    // The answer is the best we can do with full capacity W
    return prev[W];
}

};

int main() {
    int W = 50;
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    
    Solution sol;
    cout << sol.knapsack(W, val, wt) << endl; // Output: 220
    return 0;
}


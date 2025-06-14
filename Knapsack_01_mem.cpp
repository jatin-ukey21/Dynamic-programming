#include <bits/stdc++.h>
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
        // code here
        int n = wt.size();
        vector<vector<int>> dp(n,vector<int>(W+1,-1));
        return f(n - 1,W,val,wt,dp);
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
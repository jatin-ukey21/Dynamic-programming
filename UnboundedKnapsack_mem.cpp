/*
Given a set of items, each with a weight and a value, represented by the array wt and val respectively. Also, a knapsack with a weight limit capacity.
The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
Note: Each item can be taken any number of times.
*/
#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int f(int ind,int W,vector<int>& val,vector<int>& wt,vector<vector<int>>& dp){
        if(ind == 0){
            return ((int)W/wt[0]) * val[0];
        }
        if(dp[ind][W] != -1) return dp[ind][W];
        int notTake = 0 + f(ind - 1,W,val,wt,dp);
        
        int take = 0;
        if(wt[ind] <= W){
            take = val[ind] + f(ind,W - wt[ind],val,wt,dp);
        }
        
        return dp[ind][W] = max(take,notTake);
    }
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
        int n = val.size();
        vector<vector<int>> dp(n,vector<int>(capacity+1, -1));
        
        return f(n - 1,capacity,val,wt,dp);
    }
};

int main() {
    vector<int> val = {60, 100, 120};
    vector<int> wt = {10, 20, 30};
    int capacity = 50;

    Solution sol;
    cout << sol.knapSack(val, wt, capacity) << endl; // Output: 300
    return 0;
}
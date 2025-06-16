/**
Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

Note: n = size of price, and price[] is 1-indexed array.
 */

#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    int f(int ind,int n,vector<int>& price,vector<vector<int>>& dp){
        if(ind == 0){
            //creating n rods of 1 length
            return n * price[0];
        }
        
        if(dp[ind][n] != -1) return dp[ind][n];
        
        //not cut
        int notTake = 0 + f(ind - 1,n,price,dp);
        
        int rod_len = ind + 1;
        int take = INT_MIN; //bcoz we have to find max value
        if(rod_len <= n) take = price[ind] + f(ind,n - rod_len,price,dp);
        
        return dp[ind][n] = max(take,notTake);
    }
    int cutRod(vector<int> &price) {
        // code here
        int n = price.size();
        //for tabulation,initialize dp to 0
        //for memoization,initialize dp to -1
        vector<vector<int>> dp(n,vector<int>(n + 1,0));
        
        //base case:
        for(int N = 0; N <= n; N++) dp[0][N] = N * price[0];
        
        for(int ind = 1;ind < n;ind++){
            for(int N = 0; N <= n; N++){
                int notTake = 0 + dp[ind - 1][N];
                
                int rod_len = ind + 1;
                int take = INT_MIN; //bcoz we have to find max value
                if(rod_len <= N) take = price[ind] + dp[ind][N - rod_len];
        
                dp[ind][N] = max(take,notTake);
            }
        }
        
        return dp[n-1][n];
    }
};

int main() {
    vector<int> price = {1, 5, 8, 9, 10, 17, 17, 20};
    
    Solution sol;
    cout << sol.cutRod(price) << endl; // Output: 22
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

/*
You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.
Return the number of combinations that make up that amount. If that amount of money cannot be made up by any combination of the coins, return 0.
You may assume that you have an infinite number of each kind of coin.
The answer is guaranteed to fit into a signed 32-bit integer.
*/

class Solution {
public:
    int combo(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(ind == 0){
            if(amount % coins[0] == 0) return 1;
            return 0; 
        }   
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = combo(ind - 1,amount,coins,dp);

        int take = 0; //----
        //if true, we select single coin i.e 1 added
        if(coins[ind] <= amount) take = combo(ind,amount - coins[ind],coins,dp);

        return dp[ind][amount] = take + notTake;
    }
    const int MOD = 1e9 + 7;
    int change(int amount, vector<int>& coins) {
          int n = coins.size();
          //for tabulation initizlize this with 0
            //and for memoization initialize with -1
          vector<vector<int>> dp(n,vector<int>(amount+1,0));

          //base case :ind == 0
          for(int T = 0; T <= amount; T++) dp[0][T] = (T%coins[0] == 0); //1 or 0

          for(int ind = 1; ind < n; ind++){
            for(int T = 0; T <= amount; T++){
                int notTake = dp[ind - 1][T];

                int take = 0;
                if(coins[ind] <= T) take = dp[ind][T - coins[ind]];

                dp[ind][T] = (take + notTake)%MOD;
            }
          }

          return dp[n - 1][amount];
    }
};

int main() {
    vector<int> coins = {1, 2, 5};
    int amount = 5;

    Solution sol;
    cout << sol.change(amount, coins) << endl; // Output: 4
    return 0;
}
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCoins(int ind,int amount,vector<int>& coins,vector<vector<int>>& dp){
        if(ind == 0){
            //if true,we can also select this coin more then one also,
            //so return those no. of coins we can take considering coins[0]
            if(amount % coins[0] == 0) return amount/coins[0];
            return 1e9; //to avoid integer overflow and also tell that these doesn't 
            //form the case to pickup coins and is invalid
        }   
        if(dp[ind][amount] != -1) return dp[ind][amount];

        int notTake = 0 + minCoins(ind - 1,amount,coins,dp);

        int take = INT_MAX; //----
        //if true, we select single coin i.e 1 added
        if(coins[ind] <= amount) take = 1 + minCoins(ind,amount - coins[ind],coins,dp);

        return dp[ind][amount] = min(take,notTake);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));

        int ans = minCoins(n - 1,amount,coins,dp);
        if(ans >= 1e9) return -1;

        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> coins = {1, 2, 5};
    int amount = 11;
    int result = sol.coinChange(coins, amount);
    cout << "Minimum number of coins needed: " << result << endl; // Output: 3
    return 0;
}
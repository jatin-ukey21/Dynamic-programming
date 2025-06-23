#include<bits/stdc++.h>
using namespace std;

/*
You are given an array prices where prices[i] is the price of a given stock on the ith day.

Find the maximum profit you can achieve. You may complete as many transactions as you like (i.e., buy one and sell one share of the stock multiple times) with the following restrictions:

After you sell your stock, you cannot buy stock on the next day (i.e., cooldown one day).
Note: You may not engage in multiple transactions simultaneously (i.e., you must sell the stock before you buy again).
*/

class Solution {
public:
    long f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp) {
        if (ind >= prices.size())  //remember
            return 0; // even if we hold a stock,we have no further stocks to
                      // sell it and make profit
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        long profit = 0;
        if (buy) {
            // two options: buy it or not buy it
            profit = max(-prices[ind] + f(ind + 1, 0, prices, dp),
                                      0 + f(ind + 1, 1, prices, dp));
        } else {
            // two options: sell it or not sell it
            //ind + 2 means we can buy after the next day
            profit = max(prices[ind] + f(ind + 2, 1, prices, dp),
                                      0 + f(ind + 1, 0, prices, dp));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        // introducing variable 'buy' having 2 states
        // 1 - means allowed to buy
        // 0 - not allowed to buy
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));

        return f(0, 1, prices, dp);
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Output: 3
    return 0;
}
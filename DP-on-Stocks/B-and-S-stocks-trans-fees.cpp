#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    //TABULATION
    long f(int ind, int buy, vector<int>& prices, vector<vector<int>>& dp,int fee) {
        if (ind >= prices.size())  //remember
            return 0; // even if we hold a stock,we have no further stocks to
                      // sell it and make profit
        if (dp[ind][buy] != -1)
            return dp[ind][buy];
        long profit = 0;
        if (buy) {
            // two options: buy it or not buy it
            profit = max(-prices[ind] + f(ind + 1, 0, prices, dp,fee),
                                      0 + f(ind + 1, 1, prices, dp,fee));
        } else {
            // two options: sell it or not sell it
            //ind + 2 means we can buy after the next day
            profit = max(prices[ind] - fee + f(ind + 1, 1, prices, dp,fee),
                                      0 + f(ind + 1, 0, prices, dp,fee));
        }

        return dp[ind][buy] = profit;
    }
    int maxProfit(vector<int>& prices, int fee) {
        // introducing variable 'buy' having 2 states
        // 1 - means allowed to buy
        // 0 - not allowed to buy
        int n = prices.size();
        // dp[ind][buy] → max profit from day ind with buy state
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));

        dp[n][0] = 0, dp[n][1] = 0;
        // Because if we're at day n, no more transactions can be made

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if (buy) {
                    // We can choose to buy or skip
                    int buyOption = -prices[ind] + dp[ind + 1][0]; // buy and go to sell state
                    int skipOption = 0 + dp[ind + 1][1];           // don't buy
                    profit = max(buyOption, skipOption);
                } else {
                    // We can choose to sell or skip
                    int sellOption = prices[ind] - fee + dp[ind + 1][1]; // sell and go back to buy state
                    int skipOption = 0 + dp[ind + 1][0];           // don't sell
                    profit = max(sellOption, skipOption);
                }

                dp[ind][buy] = profit;
            }
        }

        return dp[0][1]; // Start from day 0 with permission to buy
    }
};

int main() {
    Solution sol;
    vector<int> prices = {1, 2, 3, 0, 2};
    int fee = 1;
    cout << "Maximum Profit: " << sol.maxProfit(prices, fee) << endl; // Output: 3
    return 0;
}
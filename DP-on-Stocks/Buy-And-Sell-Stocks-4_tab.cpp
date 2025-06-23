#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    long f(int ind, int buy, vector<int>& prices,
           vector<vector<vector<int>>>& dp, int cap) {
        if (cap == 0 || ind == prices.size())
            return 0; // even if we hold a stock,we have no further stocks to
                      // sell it and make profit
        if (dp[ind][buy][cap] != -1)
            return dp[ind][buy][cap];
        // long profit = 0;
        // sell has still not done, so transaction hasn't completed yet
        if (buy) {
            // two options: buy it or not buy it
            return dp[ind][buy][cap] =
                       max(-prices[ind] + f(ind + 1, 0, prices, dp, cap),
                           0 + f(ind + 1, 1, prices, dp, cap));
        }
        // It means previously, stock has been buyed, so selling the stock will
        // complete this transaction, so do cap - 1
        else {
            // two options: sell it or not sell it
            return dp[ind][buy][cap] =
                       max(prices[ind] + f(ind + 1, 1, prices, dp, cap - 1),
                           0 + f(ind + 1, 0, prices, dp, cap));
        }
    }
    int maxProfit(int k, vector<int>& prices) {
        // introducing variable 'buy' having 2 states
        // 1 - means allowed to buy
        // 0 - not allowed to buy

        //TABULATION
        int n = prices.size();
        vector<vector<vector<int>>> dp(
            n + 1, vector<vector<int>>(2, vector<int>(k+1, 0)));


        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                for (int cap = 1; cap <= k; cap++) {
                    if (buy == 1) {
                        // two options: buy it or not buy it
                         dp[ind][buy][cap] =
                                   max(-prices[ind] +
                                           dp[ind + 1][0][cap],
                                       0 + dp[ind + 1][1][cap]);
                    }
                    // It means previously, stock has been buyed, so selling the
                    // stock will complete this transaction if you choose to
                    // sell it, so do cap - 1
                    else {
                        // two options: sell it or not sell it
                         dp[ind][buy][cap] =
                                   max(prices[ind] +
                                           dp[ind + 1][1][cap - 1],
                                       0 + dp[ind + 1][0][cap]);
                    }
                }
            }
        }

        return dp[0][1][k];
    }
};

int main() {
    Solution sol;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    int k = 2; // Maximum number of transactions
    cout << "Maximum Profit: " << sol.maxProfit(k, prices) << endl; // Output: 7
    return 0;
}
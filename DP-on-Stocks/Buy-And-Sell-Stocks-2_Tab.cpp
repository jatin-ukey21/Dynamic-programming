#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
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
                    int sellOption = prices[ind] + dp[ind + 1][1]; // sell and go back to buy state
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
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Output: 7
    return 0;
}
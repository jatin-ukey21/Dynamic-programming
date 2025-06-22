/*
    This solution addresses the "Buy and Sell Stock III" problem, where the goal is to maximize profit 
    with at most two transactions (a transaction is a buy followed by a sell).

    Approach:
    ----------
    - The solution uses recursion with memoization (top-down dynamic programming).
    - The recursive function `f(ind, trans, prices, dp)` computes the maximum profit starting from day `ind`
      and transaction state `trans`.
    - `trans` counts the number of actions taken (buy or sell). Since each transaction consists of a buy and a sell,
      the maximum value for `trans` is 4 (0: first buy, 1: first sell, 2: second buy, 3: second sell).
    - Base cases:
        - If we've reached the end of the price list or completed 4 actions (2 transactions), return 0.
    - Memoization:
        - The `dp` table stores results for each (ind, trans) pair to avoid redundant calculations.
    - Decision:
        - If `trans` is even, it's a buy turn. We can either buy at the current price (subtract price from profit and move to next action)
          or skip (move to next day without changing action).
        - If `trans` is odd, it's a sell turn. We can either sell at the current price (add price to profit and move to next action)
          or skip (move to next day without changing action).
    - The main function initializes the DP table and starts the recursion from day 0 and transaction 0.

    Time Complexity: O(n * 4) where n is the number of days (since there are 4 possible transaction states).
    Space Complexity: O(n * 4) for the DP table.

    Example:
    --------
    Input: prices = [3, 2, 6, 5, 0, 3]
    Output: 7
    Explanation: Buy on day 2 (price=2), sell on day 3 (price=6), buy on day 5 (price=0), sell on day 6 (price=3).
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int f(int ind, int trans, vector<int>& prices, vector<vector<int>>& dp) {
        // Base cases
        if (ind == prices.size() || trans == 4) return 0;

        if (dp[ind][trans] != -1) return dp[ind][trans];

        int profit = 0;
        if (trans % 2 == 0) {
            // Buy case
            profit = max(-prices[ind] + f(ind + 1, trans + 1, prices, dp), // Buy
                         0 + f(ind + 1, trans, prices, dp));               // Skip
        } else {
            // Sell case
            profit = max(prices[ind] + f(ind + 1, trans + 1, prices, dp), // Sell
                         0 + f(ind + 1, trans, prices, dp));              // Skip
        }

        return dp[ind][trans] = profit;
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n, vector<int>(4, -1));  // 4 transactions max (0 to 3)

        return f(0, 0, prices, dp);  // Start from day 0 and transaction 0 (i.e., first buy)
    }
};
int main() {
    Solution sol;
    vector<int> prices = {3, 2, 6, 5, 0, 3};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Output: 7
    return 0;
}
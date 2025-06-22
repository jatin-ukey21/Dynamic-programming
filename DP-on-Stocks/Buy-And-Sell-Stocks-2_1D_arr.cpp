#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /**
     * Calculates the maximum profit from buying and selling stocks with as many transactions as desired.
     * Uses a space-optimized 1D dynamic programming approach.
     *
     * @param prices A vector of integers representing the stock price on each day.
     * @return The maximum profit achievable.
     *
     * The 1D array solution is significant because:
     * - It reduces space complexity from O(n*2) to O(2), using only two arrays of size 2.
     * - Instead of storing results for all days and both buy/sell states, it only keeps track of the current and next day's states.
     * - This optimization is possible because the DP state at day 'ind' only depends on day 'ind+1'.
     * - The 'ahead' array represents the DP values for the next day, while 'curr' is used for the current day.
     * - For each day and buy/sell state, the algorithm computes the best action (buy/sell/skip) and updates the current state.
     * - After processing each day, 'ahead' is updated to 'curr' for the next iteration.
     * - The final answer is found in 'ahead[1]', representing the maximum profit starting from day 0 with permission to buy.
     */
    int maxProfit(vector<int>& prices) {
        // introducing variable 'buy' having 2 states
        // 1 - means allowed to buy
        // 0 - not allowed to buy
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2,0);
        // Because if we're at day n, no more transactions can be made
    // Initialize the 'ahead' array for the base case:
    // ahead[0] = 0: No profit if not allowed to buy (must sell, but no days left)
    // ahead[1] = 0: No profit if allowed to buy (no days left to buy)
    ahead[0] = ahead[1] = 0;

        for (int ind = n - 1; ind >= 0; ind--) {
            for (int buy = 0; buy <= 1; buy++) {
                int profit = 0;

                if (buy) {
                    // We can choose to buy or skip
                    int buyOption = -prices[ind] + ahead[0]; // buy and go to sell state
                    int skipOption = 0 + ahead[1];           // don't buy
                    profit = max(buyOption, skipOption);
                } else {
                    // We can choose to sell or skip
                    int sellOption = prices[ind] + ahead[1]; // sell and go back to buy state
                    int skipOption = 0 + ahead[0];           // don't sell
                    profit = max(sellOption, skipOption);
                }

                curr[buy] = profit;
            }
            ahead = curr;
        }

        return ahead[1]; // Start from day 0 with permission to buy
    }
};

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Maximum Profit: " << sol.maxProfit(prices) << endl; // Output: 7
    return 0;
}
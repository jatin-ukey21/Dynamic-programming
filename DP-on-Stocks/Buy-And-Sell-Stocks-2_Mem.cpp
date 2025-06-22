#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        // introducing variable 'buy' having 2 states
        // 1 - means allowed to buy
        // 0 - not allowed to buy
        int n = prices.size();
        vector<int> ahead(2, 0), curr(2,0);
        // Because if we're at day n, no more transactions can be made
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

// Recursive function to calculate maximum profit
// ind: current day index
// buy: 1 if we can buy, 0 if we must sell
// prices: vector of stock prices
// Example: prices = [7,1,5,3,6,4], ind = 0, buy = 1 (start from day 0, can buy)
int solve(int ind, int buy, vector<int>& prices) {
    // Base case: If we've reached the end of the price list, no more transactions can be made
    if (ind == prices.size()) {
        return 0;
    }

    int profit = 0;

    if (buy) {
        // We have the option to buy or skip
        // Option 1: Buy the stock at current day, subtract price, move to next day with buy = 0 (must sell next)
        int buyOption = -prices[ind] + solve(ind + 1, 0, prices);
        // Option 2: Skip buying, move to next day with buy = 1 (still can buy)
        int skipOption = 0 + solve(ind + 1, 1, prices);
        // Take the maximum profit of both options
        profit = max(buyOption, skipOption);

        // Example: ind = 1, buy = 1, prices[1] = 1
        // buyOption = -1 + solve(2, 0, prices)
        // skipOption = 0 + solve(2, 1, prices)
    } else {
        // We have the option to sell or skip
        // Option 1: Sell the stock at current day, add price, move to next day with buy = 1 (can buy again)
        int sellOption = prices[ind] + solve(ind + 1, 1, prices);
        // Option 2: Skip selling, move to next day with buy = 0 (still must sell)
        int skipOption = 0 + solve(ind + 1, 0, prices);
        // Take the maximum profit of both options
        profit = max(sellOption, skipOption);

        // Example: ind = 2, buy = 0, prices[2] = 5
        // sellOption = 5 + solve(3, 1, prices)
        // skipOption = 0 + solve(3, 0, prices)
    }

    return profit;
}

int main() {
    Solution sol;
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    // Example usage of recursive function
    // Start from day 0, with permission to buy
    cout << "Maximum Profit (Recursive): " << solve(0, 1, prices) << endl; // Output: 7

    // Using the optimized DP solution
    cout << "Maximum Profit (DP): " << sol.maxProfit(prices) << endl; // Output: 7
    return 0;
}
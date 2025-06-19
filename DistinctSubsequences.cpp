#include<bits/stdc++.h>
using namespace std;    

class Solution {
public:
    // Memoization solution just for reference(little lcs)
    int f(int i, int j, string s, string t, vector<vector<int>>& dp) {
        if (j == 0)
            return 1; // means t has been fully processed
        if (i == 0)
            return 0;
        if (dp[i][j] != -1)
            return dp[i][j];
        if (s[i - 1] == t[j - 1]) {
            return dp[i][j] = f(i - 1, j - 1, s, t, dp) + f(i - 1, j, s, t, dp);
        }
        return dp[i][j] = f(i - 1, j, s, t, dp);
    }
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        // Tabulation
        vector<vector<double>> dp(
            n + 1, vector<double>(
                       m + 1, 0)); // making it double to avoid overflow cases
                    // dp[i][j] will store the number of distinct subsequences of s[0..i-1] equal to t[0..j-1]
        // base cases
        // 1. j = 0
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        // 2. i = 0
        // array is already initialzied with 0

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == t[j - 1]) {
                     dp[i][j] = dp[i - 1][j - 1] +
                                      dp[i - 1][j];
                }
                else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return (int)dp[n][m];
    }
};


int main() {
    Solution sol;
    string s = "rabbbit";
    string t = "rabbit";
    cout << "Number of distinct subsequences: " << sol.numDistinct(s, t) << endl;
    return 0;
}
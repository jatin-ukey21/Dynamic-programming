#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Recursive function to compute LCS of s[0...i-1] and t[0...j-1]
    int lcs(int i, int j, string &s, string &t, vector<vector<int>>& dp) {
        // Base Case: If either string is empty (i==0 or j==0), LCS is 0
        if(i == 0 || j == 0) return 0;

        // If already computed, return stored value
        if(dp[i][j] != -1) return dp[i][j];

        // Matching characters case
        // If current characters match, it's part of LCS
        // So include it and move both indices back
        if(s[i - 1] == t[j - 1])
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s, t, dp);

        // Not matching case:
        // Either exclude current character of s or t and take max
        return dp[i][j] = max(
            lcs(i - 1, j, s, t, dp),     // exclude character from s
            lcs(i, j - 1, s, t, dp)      // exclude character from t
        );
    }

    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();  // length of first string
        int m = text2.size();  // length of second string

        // Why pass n and m as arguments to lcs?
        // Because we are solving the problem in terms of substrings:
        // s[0...(n-1)] and t[0...(m-1)] (inclusive)
        // So lcs(n, m, ...) means: compute LCS of full strings

        // DP array initialized with -1 to indicate uncomputed states
        // dp[i][j] = LCS of s[0...i-1] and t[0...j-1]
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

        // Start recursion from the full lengths of both strings
        return lcs(n, m, text1, text2, dp);
    }
};
int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";
    
    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << result << endl; // Output: 3
    return 0;
}
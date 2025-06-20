#include<bits/stdc++.h>
using namespace std;
// This code finds the length of the Longest Palindromic Subsequence (LPS) in a given string.
// Approach Explanation:
// ---------------------------------------------------
// The LPS problem is solved by reducing it to the Longest Common Subsequence (LCS) problem.
// A palindrome reads the same forwards and backwards. So, the LPS in a string 's' is the LCS between 's' and its reverse.
// Steps:
// 1. Reverse the input string to get 't'.
// 2. Compute the LCS between the original string 's' and its reverse 't'.
// 3. The length of this LCS is the length of the LPS.
//
// Why this approach?
// - LCS is a well-known dynamic programming problem with efficient solutions.
// - By leveraging LCS, we avoid writing a separate DP for LPS and reuse a standard algorithm.
//
// Dry Run Example:
// ---------------------------------------------------
// Input: s = "bbabcbcab"
// Reverse: t = "bacbcbabb"
// LCS Table (dp) will be filled as follows (showing only a few steps):
// - dp[0][*] and dp[*][0] are initialized to 0 (base case).
// - Compare s[0]='b' with t[0]='b': match, so dp[1][1]=1+dp[0][0]=1
// - Compare s[1]='b' with t[1]='a': no match, so dp[2][2]=max(dp[1][2], dp[2][1])
// - Continue filling the table...
// Final answer: dp[n][m] = 7 (the LPS is "babcbab" or "bacbcab")
//
// Key Points:
// - Time Complexity: O(n^2), where n is the length of the string.
// - Space Complexity: O(n^2) due to the DP table.
// - Gotcha: Be careful with string indices (i-1, j-1) when filling the DP table.
//
// Example Output:
// Length of Longest Palindromic Subsequence: 7
class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2) {
        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        //base case: 
        for(int j = 0; j <= m; j++) dp[0][j] = 0;   
        for(int i = 0; i <= n; i++) dp[i][0] = 0;

        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                //maching case
                if(text1[i - 1] == text2[j - 1])
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                //not maching case
                else
                    dp[i][j] = max(dp[i - 1][j],dp[i][j - 1]);
            }
        }

        return dp[n][m];
    }
    int longestPalindromeSubseq(string s) {
        string t = s;
        reverse(t.begin(),t.end());
        return longestCommonSubsequence(s,t);
    }
};

int main() {
    Solution sol;
    string s = "bbabcbcab";
    cout << "Length of Longest Palindromic Subsequence: " << sol.longestPalindromeSubseq(s) << endl;
    return 0;
}
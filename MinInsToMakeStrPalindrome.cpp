#include<bits/stdc++.h>
using namespace std;
/*
Given a string s. In one step you can insert any character at any index of the string.
Return the minimum number of steps to make s palindrome.
A Palindrome String is one that reads the same backward as well as forward.
*/
/*
Approach Explanation:

To make a string palindrome with minimum insertions, we need to find the minimum number of characters to insert so that the string reads the same forwards and backwards.

Key Insight:
- The minimum number of insertions required is equal to the length of the string minus the length of its longest palindromic subsequence (LPS).
- This is because the LPS is the largest part of the string that is already a palindrome. The remaining characters (not in the LPS) must be inserted (possibly in reverse order) to make the whole string a palindrome.

How to find LPS:
- The LPS of a string is the longest subsequence that is a palindrome.
- The LPS can be found by computing the Longest Common Subsequence (LCS) between the string and its reverse.
- This works because a palindrome reads the same forwards and backwards, so the LCS between the string and its reverse gives the LPS.

Implementation:
- The function `longestCommonSubsequence` computes the LCS using dynamic programming.
- The function `longestPalindromeSubseq` reverses the string and calls the LCS function.
- The function `minInsertions` calculates the minimum insertions as the difference between the string's length and its LPS length.

This approach efficiently solves the problem using dynamic programming and the properties of palindromic subsequences.
*/
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
    int minInsertions(string s) {
        int n = s.length();
        int x = longestPalindromeSubseq(s);

        return n - x;
    }
};

int main() {
    Solution sol;
    string s = "abca";
    cout << "Minimum insertions to make the string palindrome: " << sol.minInsertions(s) << endl;
    return 0;
}
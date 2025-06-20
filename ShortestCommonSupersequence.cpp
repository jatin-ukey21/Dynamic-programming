#include<bits/stdc++.h>
using namespace std;

/*
Given two strings str1 and str2, return the shortest string that has both str1 and str2 as subsequences.
 If there are multiple valid strings, return any of them.
A string s is a subsequence of string t if deleting some number of characters from t (possibly 0) results in the string s.
*/
// This approach works because it first computes the Longest Common Subsequence (LCS) of the two strings.
// The LCS represents the maximal set of characters that appear in both strings in order.
// To construct the Shortest Common Supersequence (SCS), we merge the two strings by:
// - Traversing both strings from the end, and whenever characters match, we add that character to the result (since it's part of the LCS).
// - If they don't match, we add the character from the string that gives a longer LCS at that point (using the DP table).
// - After one string is exhausted, we append the remaining characters from the other string.
// - Finally, we reverse the result since we built it backwards.
// This guarantees the result is the shortest string containing both input strings as subsequences.
class Solution {
public:
    int longestCommonSubsequence(string &text1, string &text2,vector<vector<int>>& dp) {
        int n = text1.size();
        int m = text2.size();


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
    string shortestCommonSupersequence(string str1, string str2) {
        //CODE FROM LONGEST SUBSEQUENCE
        int n = str1.size();
        int m = str2.size();

        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        int len_lcs = longestCommonSubsequence(str1,str2,dp);

        //length of shortest common supersequence
        //int len = n + m - len_lcs;
        string scs = "";
        

        int i = n, j = m;
        while(i > 0 && j > 0){
            if(str1[i - 1] == str2[j - 1]){
                scs  += str1[i - 1];
                i--; j--;
            }
            else if(dp[i - 1][j] > dp[i][j - 1]){
                scs += str1[i - 1];
                i--;
            }
            else{
                scs += str2[j - 1];
                j--;
            }
           
        }
        if(i!=0){
            while(i != 0){
                scs += str1[i - 1];
                i--;
            } 
        } 
        if(j!=0){
            while(j != 0){
                scs += str2[j - 1]; 
                j--;
            }
        } 
        reverse(scs.begin(),scs.end());
        return scs;
    }
};

int main() {
    Solution sol;
    string str1 = "abac";
    string str2 = "cab";
    cout << "Shortest Common Supersequence: " << sol.shortestCommonSupersequence(str1, str2) << endl; // Output: "cabac" or "abacab" (both are valid)
    // Explanation: Both "cabac" and "abacab" contain both str1 and str2 as subsequences.
    // "cabac" contains "abac" and "cab" as subsequences.
    // "abacab" contains "abac" and "cab" as subsequences.
    // Both are valid answers, so either can be returned.
    // Note: The output may vary based on the implementation details, but it will always be a valid supersequence.
    return 0;
}
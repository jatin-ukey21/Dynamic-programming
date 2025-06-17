#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lcs(int i, int j, const string &s, const string &t, vector<vector<int>> &dp) {
        if (i == 0 || j == 0) return 0;

        if (dp[i][j] != -1) return dp[i][j];

        //matching case
        if (s[i - 1] == t[j - 1])
            return dp[i][j] = 1 + lcs(i - 1, j - 1, s, t, dp);
        //not matching case
        return dp[i][j] = max(
            lcs(i - 1, j, s, t, dp),
            lcs(i, j - 1, s, t, dp)
        );
    }

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
};
int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";

    int result = sol.longestCommonSubsequence(text1, text2);
    cout << "Length of Longest Common Subsequence: " << result << endl; // Output: 3
    return 0;
}
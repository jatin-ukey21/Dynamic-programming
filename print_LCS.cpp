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

    string longestCommonSubsequence(string &text1, string &text2) {
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

        // Reconstruct the LCS string from the dp table
        string lcs_str = "";
        int len = dp[n][m];
        for (int i = 0; i < len; i++)
        {
            lcs_str += '$';
        }
        
        
        int i = n, j = m;
        while (i > 0 && j > 0)
        {
            if (text1[i - 1] == text2[j - 1])
            {
                lcs_str[len - 1] = text1[i - 1];
                i--;
                j--;        
                len--;
            }
            else if (dp[i - 1][j]  > dp[i][j - 1])
            {
                i--;
            }
            else
            {
                j--;
            }
            
        }
        
        return lcs_str;
    }
};

/*
Dry run for text1 = "abcde", text2 = "ace":

Step 1: Fill the DP matrix (dp[i][j] = length of LCS of text1[0..i-1], text2[0..j-1])

    a  c  e
   0 0  0  0  0
a  0 1  1  1
b  0 1  1  1
c  0 1  2  2
d  0 1  2  2
e  0 1  2  3

Step 2: Trace the LCS using the while loop:

Initialize: i = 5, j = 3, len = 3, lcs_str = "$$$"

while (i > 0 && j > 0):
    - At i=5, j=3: text1[4]='e', text2[2]='e' (match)
        -> lcs_str[2] = 'e', i--, j--, len--
        -> Now: i=4, j=2, len=2
    - At i=4, j=2: text1[3]='d', text2[1]='c' (not match)
        -> dp[3][2] >= dp[4][1], so i--
        -> Now: i=3, j=2
    - At i=3, j=2: text1[2]='c', text2[1]='c' (match)
        -> lcs_str[1] = 'c', i--, j--, len--
        -> Now: i=2, j=1, len=1
    - At i=2, j=1: text1[1]='b', text2[0]='a' (not match)
        -> dp[1][1] >= dp[2][0], so i--
        -> Now: i=1, j=1
    - At i=1, j=1: text1[0]='a', text2[0]='a' (match)
        -> lcs_str[0] = 'a', i--, j--, len--
        -> Now: i=0, j=0, len=0

Result: lcs_str = "ace"
*/

int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "ace";

    string result = sol.longestCommonSubsequence(text1, text2);
    cout << "Longest Common Subsequence: " << result << endl; // Output: "ace"
    return 0;
}
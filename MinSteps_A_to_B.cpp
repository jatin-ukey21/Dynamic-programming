#include<bits/stdc++.h>
using namespace std;

/*
Given two strings word1 and word2, return the minimum number of steps required to make word1 and word2 the same.

In one step, you can delete exactly one character in either string. or you can insert exactly one character in either string.
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
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        /*
            💡 Why this works:

            - The LCS represents the **common characters** between word1 and word2 
              that are already aligned and don't need to be changed.

            - To convert word1 to word2:
                ➤ We need to **delete** all characters in word1 that are NOT part of LCS → (n - lcs)
                ➤ We need to **insert** characters from word2 that are NOT in LCS → (m - lcs)

            🔁 So, total operations = deletions + insertions = (n - lcs) + (m - lcs)
            🔁 OR: total = n + m - 2 * lcs

            ✅ This formula ensures minimal operations to make both strings equal.
        */
        int lcs = longestCommonSubsequence(word1,word2);
        int deletions = n - lcs;
        int insertions = m - lcs;
        
        return deletions + insertions;
        //or return n + m - 2*lcs,derived by adding both operations
    }
};

int main() {
    Solution sol;
    string word1 = "sea";
    string word2 = "eat";
    cout << "Minimum steps to make word1 and word2 the same: " << sol.minDistance(word1, word2) << endl; // Output: 2
    // Explanation: 
    // - Delete 's' from "sea" to get "ea"
    // - Insert 't' to "ea" to get "eat"    
    // Total steps = 1 (deletion) + 1 (insertion) = 2
    return 0;
}
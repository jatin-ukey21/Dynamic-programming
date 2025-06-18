#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestCommonSubstr(string& s1, string& s2) {
        // your code here
        int n = s1.length();
        int m = s2.length();
        vector<vector<int>> dp(n + 1,vector<int>(m + 1,0));
        
        //base case when i == 0 or j == 0, means end of string reached in recursion
        for(int j = 0; j <= m; j++) dp[0][j] = 0;
        for(int i = 0; i <= n; i++) dp[i][0] = 0;
        /*
         note that dp[i][j] here indicates the length of longest substring
         ending at index i of the s1 and index j of s2 string.
        */
        int ans = 0;
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i - 1] == s2[j - 1]){
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    ans = max(ans,dp[i][j]);
                }
                else{
                    dp[i][j] = 0; //means we did not find any common substring 
                    //till i and j index in s1 and s2
                }
            }
        }
        
        return ans;
    }

    string longestCommonSubstring(string& text1, string& text2) {
        int n = text1.size();
        int m = text2.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        
        // Base case: when i == 0 or j == 0, means end of string reached in recursion
        for (int j = 0; j <= m; j++) dp[0][j] = 0;
        for (int i = 0; i <= n; i++) dp[i][0] = 0;

        int maxLength = 0;
        int endIndex = -1; // To store the end index of the longest common substring

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                    if (dp[i][j] > maxLength) {
                        maxLength = dp[i][j];
                        endIndex = i - 1; // Update end index of the longest common substring
                    }
                } else {
                    dp[i][j] = 0; // Reset to zero if characters do not match
                }
            }
        }

        // If no common substring found, return an empty string
        if (maxLength == 0) return "";

        // Reconstruct the longest common substring
        return text1.substr(endIndex - maxLength + 1, maxLength);
    }
};

int main() {
    Solution sol;
    string text1 = "abcde";
    string text2 = "abfce";
    
    int length = sol.longestCommonSubstr(text1, text2);
    cout << "Length of Longest Common Substring: " << length << endl; // Output: 2

    string lcs_str = sol.longestCommonSubstring(text1, text2);
    cout << "Longest Common Substring: " << lcs_str << endl; // Output: "ab"

    return 0;
}
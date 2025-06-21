#include<bits/stdc++.h>
using namespace std;

/*
44. Wildcard Matching
Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*' where:

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).
The matching should cover the entire input string (not partial).

The problem can be solved using dynamic programming. We will create a 2D DP table where dp[i][j] indicates whether the first i characters of the string s match the first j characters of the pattern p.
*/

class Solution {
public:
    bool f(int i, int j, string& s, string& p, vector<vector<int>>& dp) {
        if (i == 0 && j == 0)
            return true;

        if (i == 0) {
            for (int k = j - 1; k >= 0; k--) {
                if (p[k] != '*')
                    return false;
            }
            return true;
        }

        if (j == 0)
            return false;

        if (dp[i][j] != -1)
            return dp[i][j];

        if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
            return dp[i][j] = f(i - 1, j - 1, s, p, dp);

        if (p[j - 1] == '*')
            return dp[i][j] = f(i, j - 1, s, p, dp) || f(i - 1, j, s, p, dp);

        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.size(), m = p.size();
        // for tabulation
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
        
        return f(n, m, s, p, dp);
    }
};

int main() {
    Solution solution;
    string s = "adceb";
    string p = "*a*b";
    bool result = solution.isMatch(s, p);
    cout << (result ? "true" : "false") << endl; // Output: true
    return 0;
}
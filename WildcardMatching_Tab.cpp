#include<bits/stdc++.h>
using namespace std;

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
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // base cases
        dp[0][0] = true;
        // when i==0
        for (int j = 1; j <= m; j++) {
            bool allStars = true;
            for (int k = 1; k <= j; k++) {
                if (p[k - 1] != '*') {
                    allStars = false;
                    break;
                }
            }
            dp[0][j] = allStars;
        }
        // when j == 0
        for (int i = 1; i <= n; i++)
            dp[i][0] = false;

        // possibilies
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (s[i - 1] == p[j - 1] || p[j - 1] == '?')
                    dp[i][j] = dp[i - 1][j - 1];
                else if (p[j - 1] == '*')
                    dp[i][j] = dp[i][j - 1] || dp[i - 1][j];
                else
                    dp[i][j] = false;
            }
        }

        return dp[n][m];
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
//tabulation approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // here starting points are fixed,ending points are variable
    
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<vector<int>>> dp(
            n, vector<vector<int>>(m, vector<int>(m, -1)));
        // Base case if we are at last row:
        for (int j1 = 0; j1 < m; j1++) {
            for (int j2 = 0; j2 < m; j2++) {
                if (j1 == j2)
                    dp[n - 1][j1][j2] = grid[n - 1][j1];
                else
                    dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }

        for (int i = n - 2; i >= 0; i--) {
            for (int j1 = 0; j1 < m; j1++) {
                for (int j2 = 0; j2 < m; j2++) {
                    int maxi = -1e8;
                    // exloring all travelling paths of both the robots
                    for (int dj1 = -1; dj1 <= +1; dj1++) {
                        for (int dj2 = -1; dj2 <= +1; dj2++) {
                            int val;
                            if (j1 == j2)
                                val = grid[i][j1];
                            else
                                val = grid[i][j1] + grid[i][j2];

                            if(j1 + dj1 >= 0 && j1 + dj1 < m && j2 + dj2 >= 0 && j2 + dj2 < m) val += dp[i + 1][j1 + dj1][j2 + dj2];
                            else val += -1e8;
                            maxi = max(maxi, val);
                        }
                    }

                    dp[i][j1][j2] = maxi;
                }
            }
        }

        return dp[0][0][m-1];
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {3, 1, 1},
        {2, 5, 1},
        {1, 5, 5},
        {2, 1, 1}
    };
    cout << sol.cherryPickup(grid) << endl; // Output: 24
    return 0;
}
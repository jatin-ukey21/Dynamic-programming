//memoization approach
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    //here starting points are fixed,ending points are variable
    int f(int i,int j1,int j2,int r,int c,vector<vector<int>>& grid,vector<vector<vector<int>>>& dp){
        //invalid case
        if(j1 < 0 || j1 >= c || j2 < 0 || j2 >= c){
            return -1e8;
        }
        //last row
        if(i == r - 1){
            //if both robots rich the same cell
            if(j1 == j2) return grid[i][j1];
            else return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxi = -1e8;
        //exloring all travlling paths of both the robots
        for(int dj1 = -1; dj1 <= +1; dj1++){
            for(int dj2 = -1; dj2 <= +1; dj2++){
                int val;
                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];

                val += f(i+1,j1 + dj1,j2 + dj2,r,c,grid,dp);
                maxi = max(maxi,val);
            }
        }

        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int r = grid.size();
        int c = grid[0].size();

        vector<vector<vector<int>>> dp(r,vector<vector<int>>(c,vector<int>(c,-1)));
        return f(0,0,c-1,r,c,grid,dp);
    }
};

int main() {
    Solution sol;
    vector<vector<int>> grid = {
        {3,1,1},
        {2,5,1},
        {1,5,5},
        {2,1,1}
    };
    cout << sol.cherryPickup(grid) << endl; // Output: 24
    return 0;
}
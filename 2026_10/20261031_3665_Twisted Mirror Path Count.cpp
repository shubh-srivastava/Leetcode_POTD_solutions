// 31st October 2026

class Solution {
public:
int M = 1e9 + 7;
int n,m;
    int solve(int i,int j,int prev,vector<vector<int>>&grid,vector<vector<vector<int>>> & dp){
        if(i < 0 || i >= n || j < 0 || j >= m){
            return 0;
        }
        if(i == n-1 && j == m-1){
            return 1;
        }
        if(dp[i][j][prev+1] != -1){
            return dp[i][j][prev+1];
        }
        int right = 0;
        int down = 0;
        if(grid[i][j] == 1){
            if(prev == 0){
                down = solve(i+1,j,1,grid,dp);
            }
            else{
                right = solve(i,j+1,0,grid,dp);
            }
        }
        else{
            down = solve(i+1,j,1,grid,dp);
            right = solve(i,j+1,0,grid,dp);
        }
        return dp[i][j][prev+1] = (right + down)%M;
    }
    int uniquePaths(vector<vector<int>>& grid){
        n = grid.size();
        m = grid[0].size();
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1)));
        return solve(0,0,-1,grid,dp);

    }
};
// 25th October 2026

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int r, int c){
        if (r < 0 || c < 0 || r >= (int)grid.size() || c >= (int)grid[0].size() || grid[r][c] != 0){
            return;
        }
        grid[r][c] = 1;
        dfs(grid, r + 1, c);
        dfs(grid, r - 1, c);
        dfs(grid, r, c + 1);
        dfs(grid, r, c - 1);
    }

    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if ((i == 0 || j == 0 || i == n - 1 || j == m - 1) && grid[i][j] == 0){
                    dfs(grid, i, j);
                }
            }
        }

        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j] == 0){
                    count++;
                    dfs(grid, i, j);
                }
            }
        }
        return count;
    }

};
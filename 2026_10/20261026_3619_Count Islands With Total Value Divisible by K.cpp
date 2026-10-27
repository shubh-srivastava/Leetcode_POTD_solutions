// 26th Ocober 2026

class Solution {
public:
    int n,m;
    void dfs(int r,int c,vector<vector<int>>& grid,vector<vector<int>>&vis,long long &sum){
        sum = sum + 0LL + grid[r][c];
        vis[r][c] = 1;
        int delr[] = {1,0,-1,0};
        int delc[] = {0,1,0,-1};
    
        for(int i=0;i<4;i++){
            int nr = r + delr[i];
            int nc = c + delc[i];
            if(nr >= 0 && nr < n && nc >=0 && nc < m && grid[nr][nc] != 0 && vis[nr][nc] == 0){
                dfs(nr,nc,grid,vis,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k){
        n = grid.size();
        m = grid[0].size();    
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans = 0;
        long long sum=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                sum = 0;
                if(grid[i][j] != 0 && vis[i][j] == 0){
                    dfs(i,j,grid,vis,sum);
                    if(sum%(1LL*k) == 0){
                        ans++;
                    }
                }
            }
        }            
        return ans;
    }
};
// 20th July 2026

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k){
        int n = grid.size();
        int m = grid[0].size();
        int total = m*n;
        k %= total;
        vector<vector<int>>ans(n,vector<int>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int nr = ((i*m + j + k)%total)/m;
                int nc = ((i*m + j + k)%total)%m;
                ans[nr][nc] = grid[i][j];
            }
        }    
        return ans;    
    }
};
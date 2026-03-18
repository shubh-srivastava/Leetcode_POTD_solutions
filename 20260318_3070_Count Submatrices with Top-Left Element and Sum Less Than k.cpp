// 18th March 2026

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k){
        int n = grid.size();
        int m = grid[0].size();
        int curr = grid[0][0];
        vector<vector<int>>sum(n,vector<int>(m,0));
        sum[0][0] = grid[0][0];
        int ans = 0;
        if(sum[0][0] <= k){
            ans++;
        }
        
        for(int j=1;j<m;j++){
            curr += grid[0][j];
            sum[0][j] = curr;
            if(sum[0][j] <= k){
                ans++;
            }
        }   
        curr = grid[0][0];    
        for(int i=1;i<n;i++){
            curr += grid[i][0];
            sum[i][0] = curr;
            if(sum[i][0] <= k){
                ans++;
            }
        }
        
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                int up = sum[i-1][j];
                int left = sum[i][j-1];
                int dl = sum[i-1][j-1];
                sum[i][j] = grid[i][j] + up + left - dl;
                if(sum[i][j] <= k){
                    ans++;
                }
            }
        }
        return ans;
    }
};
// 24th March 2026

class Solution {
public:
    vector<vector<int>> constructProductMatrix(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int M = 12345;
        vector<int>ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                ans.push_back(grid[i][j]);
            }
        }
        int N = ans.size();
        vector<long long>prefix(N,1);
        vector<long long>suffix(N,1);
        
        for(int i=1;i<N;i++){
            prefix[i] = (1LL *prefix[i-1] * ans[i-1])%M;
        }
        for(int i=N-2;i>=0;i--){
            suffix[i] = (1LL *suffix[i+1] * ans[i+1])%M;
        }
        vector<vector<int>>ret(n,vector<int>(m,1));

        for(int i=0;i<N;i++){
            int r = i/m;
            int c = i%m;
            ret[r][c] = (1LL * prefix[i] * suffix[i])%M;
        }
        return ret;
    }
};
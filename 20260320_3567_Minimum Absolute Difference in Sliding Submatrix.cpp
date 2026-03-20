// 20th March 2026

class Solution {
public:
    int find(int r,int c,int k,vector<vector<int>>&grid){
        set<int>s;
        for(int i=r;i<r+k;i++){
            for(int j=c;j<c+k;j++){
                s.insert(grid[i][j]);
            }
        }
        if(s.size() == 1){
            // cout<<r<<' '<<c<<" "<<s.size()<<endl;
            return 0;
        }
        vector<int>dist;
        for(int i :s){
            dist.push_back(i);
        }
        int ans = INT_MAX;
        int n = dist.size();
        for(int i=1;i<n;i++){
            ans = min(ans,dist[i] - dist[i-1]);
        }
        return ans;
    }
    vector<vector<int>> minAbsDiff(vector<vector<int>>& grid, int k){
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>ret;
        for(int i=0;i<=n-k;i++){
            vector<int>ans;
            for(int j=0;j<=m-k;j++){
                ans.push_back(find(i,j,k,grid));
                // cout<<i<<" "<<j<<" "<<find(i,j,k,grid)<<endl;
            }
            ret.push_back(ans);
        }
        
        
        return ret;
    }
};
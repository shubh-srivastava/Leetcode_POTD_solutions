// 26th March 2026

class Solution {
public:
long long total = 0;
    bool checkHorCuts(vector<vector<int>>&grid){
        int n = grid.size();
        int m = grid[0].size();

        unordered_set<long long>st;
        long long top = 0;

        for(int i=0;i<=n-2;i++){
            for(int j=0;j<m;j++){
                st.insert(grid[i][j]);
                top += grid[i][j];
            }
            long long bottom = (total - top);
            long long diff = top - bottom;

            if(diff == 0)return true;
            if(diff == (long long)grid[0][0])return true;
            if(diff == (long long)grid[0][m-1])return true;
            if(diff == (long long)grid[i][0]) return true;

            if(i > 0 && m > 1 && st.count(diff)){
                return true;
            }
        }
        return false;
    }
    bool canPartitionGrid(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                total += grid[i][j];
            }
        }
        //checking horizontalcuts
        if(checkHorCuts(grid)){
            return true;
        }   
        reverse(begin(grid),end(grid));

        if(checkHorCuts(grid)){
            return true;
        }
        reverse(begin(grid),end(grid));

        vector<vector<int>>trans(m,vector<int>(n,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                trans[j][i] = grid[i][j];
            }
        }
        if(checkHorCuts(trans)){
            return true;
        }
        reverse(begin(trans),end(trans));
        if(checkHorCuts(trans)){
            return true;
        }
        return false;
    }
};
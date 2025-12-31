class Solution {
public:
    bool f(int i,int j,vector<vector<int>>&grid){
        if(grid[i][j]+grid[i][j+1]+grid[i][j+2] != 15){
            return false;
        }
        if(grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2] != 15){
            return false;
        }
        if(grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2] != 15){
            return false;
        }
        if(grid[i][j]+grid[i+1][j]+grid[i+2][j] != 15){
            return false;
        }
        if(grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1] != 15){
            return false;
        }
        if(grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2] != 15){
            return false;
        }
        if(grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2] != 15){
            return false;
        }
        if(grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2] != 15){
            return false;
        }
        vector<int>hash(10,-1);
        for(int r=0;r<3;r++){
            for(int c=0;c<3;c++){
                if(grid[i+r][j+c] >= 10){
                    return false;
                }
                else{
                    hash[grid[i+r][j+c]] = 1;
                }
            }
        }
        for(int i=1;i<=9;i++){
            if(hash[i] == -1){
                return false;
            }
        }
        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        for(int i=0;i+2<n;i++){
            for(int j=0;j+2<m;j++){
                if(f(i,j,grid)){
                    ans++;
                }
            }
        }
        return ans;
    }
};
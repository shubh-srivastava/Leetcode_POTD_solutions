class Solution {
public:
int n,m;
    int solve(vector<vector<int>>&grid,vector<vector<int>>&row,vector<vector<int>>&col,int x,int y,int len){
        int target = row[x][y + len] - row[x][y];

        for(int i=0;i<len;i++){
            if(row[x+i][y+len] - row[x+i][y] != target){
                return false;
            }
        }

        for(int j=0;j<len;j++){
            if(col[x+len][y+j] - col[x][y+j] != target){
                return false;
            }
        }

        int d1 = 0;
        int d2 = 0;
        for(int k=0;k<len;k++){
            d1 += grid[x+k][y+k];
            d2 += grid[x+len-k-1][y+k];
        }

        return d1 == target && d2 == target;
        
    }
    int largestMagicSquare(vector<vector<int>>& grid){
        n = grid.size();
        m = grid[0].size();
        vector<vector<int>>row(n,vector<int>(m+1,0));
        vector<vector<int>>col(n+1,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                row[i][j+1] = row[i][j] + grid[i][j];
            }
        }     

        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                col[i+1][j] = col[i][j] + grid[i][j];
            }
        }

        int ans = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int maxsize = min(n-i,m-j);
                for(int sz = maxsize;sz>ans;sz--){
                    if(solve(grid,row,col,i,j,sz)){
                        ans = sz;
                        break;
                    }
                }
            }
        }
        return ans;
    }
};
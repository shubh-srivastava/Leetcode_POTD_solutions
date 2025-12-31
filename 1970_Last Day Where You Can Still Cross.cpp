// 31st December 2025
class Solution {
public:
int R;
int C;

    bool dfs(int r,int c,vector<vector<int>>&grid){
        if(r<0 || r>=R || c<0 || c>=C || grid[r][c] == 1){
            return false;
        }
        if(r == R-1){
            return true;
        }
        
        // mark visited
        grid[r][c] = 1;
        int delr[] = {1,0,0,-1};
        int delc[] = {0,1,-1,0};
        for(int i=0;i<4;i++){
            int nr = r + delr[i];
            int nc = c + delc[i];

            if(nr>= 0 && nr<R && nc>=0 && nc<C && grid[nr][nc] == 0 && dfs(nr,nc,grid)){
                return true;
            }
        }
        return false;
    }
    bool canCross(int mid,vector<vector<int>>&cells){
        vector<vector<int>>grid(R,vector<int>(C,0));
        for(int i=0;i<=mid;i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }

        for(int j=0;j<C;j++){
            if(grid[0][j] == 0 && dfs(0,j,grid)){
                return true;
            }
        }
        return false;
    }

    int latestDayToCross(int row, int col, vector<vector<int>>& cells){
        R = row;
        C = col;
        int lo = 0;
        int hi = cells.size()-1;
        int lastDay = 0;

        while(hi >= lo){
            int mid = (hi+lo)/2;

            if(canCross(mid,cells)){
                lo = mid + 1;
            }
            else{
                hi = mid-1;
            }
        }
        return lo;
    }
};

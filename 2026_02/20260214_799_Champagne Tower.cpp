//14th feb 2026

class Solution {
public:
double pour;
double dp[101][101];
    double solve(int r,int c){      
        if(r < 0 || c < 0 || r < c){
            return 0.0;
        }
        if(r == 0 && c == 0){
            return pour;
        }
        if(dp[r][c] != -1)return dp[r][c];
        double left = (solve(r-1,c-1)-1.0)/2.0;
        double right = (solve(r-1,c)-1.0)/2.0;
        
        if(left < 0){
            left = 0.0;
        }
        if(right < 0){
            right = 0.0;
        }
        return dp[r][c] = right + left;
    }

    double champagneTower(int poured, int query_row, int query_glass){
        for(int i=0;i<101;i++){
            for(int j=0;j<101;j++){
                dp[i][j] = -1;
            }
        }
        pour = poured;
        return min(1.0,solve(query_row,query_glass));
    }
};
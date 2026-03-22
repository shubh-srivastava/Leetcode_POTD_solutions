// 22nd March 2026

class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target){
        int n = mat.size();
        bool ch1 = true,ch2=true,ch3=true,ch4=true;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j] != target[i][j]){
                    ch1 = false;
                }
                if(mat[i][j] != target[j][n - i - 1]){
                    ch2 = false;
                }
                if(mat[i][j] != target[n-i-1][n-j-1]){
                    ch3 = false;
                }
                if(mat[i][j] != target[n-j-1][i]){
                    ch4 = false;
                }
                if(!ch1 && !ch2 && !ch3 && !ch4){
                    return false;
                }
            }
        }        
        return true;
    }
};
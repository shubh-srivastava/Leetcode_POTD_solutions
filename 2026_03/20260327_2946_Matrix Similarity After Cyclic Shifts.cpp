// 27th March 2027

class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k){
        int n = mat.size();
        int m = mat[0].size();
        k = k%m;

        vector<vector<int>>temp(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            if(i%2 == 0){
                for(int j=0;j<m;j++){
                    temp[i][(j - k + m)%m] = mat[i][j];
                }
            }
            else{
                for(int j=0;j<m;j++){
                    temp[i][(j + k + m)%m] = mat[i][j];
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] != temp[i][j]){
                    return false;
                }
            }
        }                
        return true;
    }
};
// 17th March 2026

class Solution {
public:
int n,m;
    int largestSubmatrix(vector<vector<int>>& matrix){
        n = matrix.size();
        m = matrix[0].size();

        for(int j=0;j<m;j++){
            int con = 0;
            for(int i=0;i<n;i++){
                if(matrix[i][j] == 1){
                    con++;
                    matrix[i][j] = con;
                }
                else{
                    con = 0;
                }
            }
        }

        for(int i=0;i<n;i++){
            sort(matrix[i].begin(),matrix[i].end());
        }

        int ans = 0;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int height = matrix[i][j];
                int width = m-j;
                ans = max(ans,height*width);
            }
        }
        return ans;
    }
};
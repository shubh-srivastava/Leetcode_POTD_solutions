// 4th May 2026

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        int top = 0;
        int bottom = n - 1;

        while(top<bottom){
            for(int col=0;col<n;col++){
                swap(matrix[bottom][col],matrix[top][col]);
            }
            top++;
            bottom--;
        }
        for(int row=0;row<n;row++){
            for(int col=row+1;col<n;col++){
                swap(matrix[col][row],matrix[row][col]);
            }
        }        
    }
};
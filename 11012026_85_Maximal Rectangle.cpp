// 11th JAN 2026 
class Solution {
public:

    vector<int> psef(vector<int> &row){
        vector<int>pse(row.size());
        stack<int> st;
        for(int i=0;i<row.size();i++){
            while(!st.empty() && row[st.top()] >= row[i]){
                st.pop();
            }
            if(st.empty()){
                pse[i] = -1;
            }
            else{
                pse[i] = st.top();
            }
            st.push(i);
        }
        return pse;
    }
    vector<int> nsef(vector<int> &row){
        vector<int>nse(row.size());
        stack<int> st;
        for(int i=row.size()-1;i>=0;i--){
            while(!st.empty() && row[st.top()] >= row[i]){
                st.pop();
            }
            if(st.empty()){
                nse[i] = row.size();
            }
            else{
                nse[i] = st.top();
            }
            st.push(i);
        }
        return nse;
    }

    int maximalRectangle(vector<vector<char>>& matrix){
        int maxrec = 0;
        int n=matrix.size(),m=matrix[0].size();
        vector<int> height(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j] == '1'){
                    height[j]++;
                }
                else{
                    height[j]=0;
                }
            }
            vector<int> pse = psef(height);
            vector<int> nse = nsef(height);
            for (int j = 0; j < m; j++) {
                int width = nse[j] - pse[j] - 1;
                maxrec = max(maxrec, width * height[j]);
            }
        }                
        return maxrec;
    }
};
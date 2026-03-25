// 25th March 2026

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();

        vector<long long>rsum(n,0);
        for(int i=0;i<n;i++){
            long long sum = 0;
            for(int j=0;j<m;j++){
                sum += grid[i][j];
            }
            rsum[i] = sum;
        }        
        vector<long long>csum(m,0);
        for(int j=0;j<m;j++){
            long long sum = 0;
            for(int i=0;i<n;i++){
                sum += grid[i][j];
            }
            csum[j] = sum;
        }
        vector<long long>rrsum(n,0);
        vector<long long>rcsum(m,0);

        rrsum[n-1] = rsum[n-1];
        for(int i=n-2;i>=0;i--){
            rrsum[i] = rrsum[i+1] + rsum[i];
        }
        rcsum[m-1] = csum[m-1];
        for(int j=m-2;j>=0;j--){
            rcsum[j] = rcsum[j+1] + csum[j];
        }

        for(int i=1;i<n;i++){
            rsum[i] += rsum[i-1];
        }
        for(int j=1;j<m;j++){
            csum[j] += csum[j-1];
        }
        for(int i=1;i<n;i++){
            if(rsum[i-1] == rrsum[i]){
                return true;
            }
        }      
        for(int j=1;j<m;j++){
            if(csum[j-1] == rcsum[j]){
                return true;
            }
        }      
        return false;
    }
};

class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        long long total = 0;
        for (auto &row : grid){
            for (auto &val : row){
                total += val;
            }
        }
        if (total % 2 != 0) return false;

        long long target = total / 2;
        long long curr = 0;
        for(int i=0;i<n-1;i++) {
            for(int j=0;j<m;j++){
                curr += grid[i][j];
            }
            if(curr == target){ 
                return true;
            }
        }

        curr = 0;
        for(int j=0;j<m-1;j++){
            for(int i=0;i<n;i++){
                curr += grid[i][j];
            }
            if (curr == target) return true;
        }

        return false;
    }
};
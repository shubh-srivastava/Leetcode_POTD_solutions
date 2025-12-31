class Solution {
public:
    int ub(int n,vector<int>&arr){
        int hi = n-1;
        int lo = 0;

        while(hi >= lo){
            int mid = (hi+lo)/2;

            if(arr[mid] >= 0){
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }
        return lo;
    }
    int countNegatives(vector<vector<int>>& grid){
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        for(int i=0;i<n;i++){
            int num = m - ub(m,grid[i]);
            ans += num;
        }
        return ans;        
    }
};
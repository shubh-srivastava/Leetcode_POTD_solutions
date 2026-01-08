// 8th JAN 2026
class Solution {
public:
int n,m;

    int solve(vector<int>&nums1,vector<int>&nums2,int i,int j,vector<vector<int>>&dp){
        if(i == n || j == m){
            return -1e9;
        }
        if(dp[i][j] != -1)return dp[i][j];
        int val = nums1[i]*nums2[j];
        int both = nums1[i]*nums2[j] + solve(nums1,nums2,i+1,j+1,dp);
        int take_i = solve(nums1,nums2,i,j+1,dp);
        int take_j = solve(nums1,nums2,i+1,j,dp);

        return dp[i][j] = max(val,max(both,max(take_i,take_j)));

    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2){
        n = nums1.size();
        m = nums2.size();
        
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solve(nums1,nums2,0,0,dp);

    }
};
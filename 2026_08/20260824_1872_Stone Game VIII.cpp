// 24th August 2026

class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int n = stones.size();
        vector<int>prefixSum(n,0);
        vector<int>dp(n,0);
        prefixSum[0] = stones[0];
        for(int i=1;i<n;i++){
            prefixSum[i] = prefixSum[i-1] + stones[i];
        }
        dp[n-1] = prefixSum[n-1];
        for(int i=n-2;i>=1;i--){
            int take = prefixSum[i] - dp[i+1];
            int skip = dp[i+1];
            dp[i] = max(skip,take);
        }
        return dp[1];
    }
};
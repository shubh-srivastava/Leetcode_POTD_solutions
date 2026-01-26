// 22 December 2025
class Solution {
public:
    int minDeletionSize(vector<string>& strs){
        int n = strs[0].size();
        int numstr = strs.size();
        vector<int>dp(n,1);
        int maxi = 1;

        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                int k=0;
                while(k<numstr){
                    if(strs[k][j] <= strs[k][i]){
                        k++;
                    }
                    else{
                        break;
                    }
                }
                if(k == numstr){
                    dp[i] = max(dp[i],dp[j]+1);
                }
            }
            maxi = max(maxi,dp[i]);
        }
        
        return n-maxi;
    }
};
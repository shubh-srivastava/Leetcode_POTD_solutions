// 2nd April 2026

class Solution {
public:
    int maximumAmount(vector<vector<int>>& coins){
        int n = coins.size();
        int m = coins[0].size();

        vector<vector<vector<int>>>dp(n,vector<vector<int>>(m,vector<int>(3,-1e9)));
        for(int k=0;k<3;k++){
            if(coins[0][0] >= 0){
                dp[0][0][k] = coins[0][0];
            }
            else{
                if(k > 0){
                    dp[0][0][k] = 0;
                }
                dp[0][0][k] = max(dp[0][0][k],coins[0][0]);
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i == 0 && j == 0)continue;

                for(int k=0;k<3;k++){
                    int prev = -1e9;
                    if(i > 0){
                        prev = max(prev,dp[i-1][j][k]);
                    }
                    if(j > 0){
                        prev = max(prev,dp[i][j-1][k]);
                    }
                    if(prev == -1e9)continue;

                    dp[i][j][k] = max(dp[i][j][k],prev + coins[i][j]);

                    if(coins[i][j] < 0 && k > 0){
                        int skip = -1e9;
                        if(i > 0){
                            skip = max(skip,dp[i-1][j][k-1]);
                        }
                        if(j > 0){
                            skip = max(skip,dp[i][j-1][k-1]);
                        }
                        if(skip != -1e9){
                            dp[i][j][k] = max(dp[i][j][k],skip);
                        }

                    }
                }
            }
        }

        return max({dp[n-1][m-1][0],dp[n-1][m-1][1],dp[n-1][m-1][2]});

    }
};
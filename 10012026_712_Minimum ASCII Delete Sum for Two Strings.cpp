class Solution {
public:
int n,m;
    int minimumDeleteSum(string s1, string s2){
        n = s1.size();
        m = s2.size();

        vector<vector<int>>dp(n+2,vector<int>(m+2,0));

        for(int i=n;i>=0;i--){
            for(int j=m;j>=0;j--){
                if(i == n){
                    dp[i][j] = s2[j] + dp[i][j+1];
                }
                else if(j == m){
                    dp[i][j] = s1[i] + dp[i+1][j];
                }
                else if(s1[i] == s2[j]){
                    dp[i][j] = dp[i+1][j+1];
                }
                else{
                    int del_i = s1[i] + dp[i+1][j];
                    int del_j = s2[j] + dp[i][j+1];

                    dp[i][j] = min(del_i,del_j);
                }
            }
        }
        return dp[0][0];
    }
};
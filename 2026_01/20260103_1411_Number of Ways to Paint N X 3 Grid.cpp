// 3rd JAN 2026 
// the first one is memoization 
class Solution {
public:
    int solve(int r,int n,int p1,int p2,int p3,vector<vector<vector<vector<int>>>> &dp,int mod){
        if(r == n){
            return 1;
        }
        if(dp[r][p1][p2][p3] != -1){
            return dp[r][p1][p2][p3];
        }
        int ans = 0;
        for(int i=1;i<=3;i++){
            if(i == p1)continue;

            for(int j=1;j<=3;j++){
                if(j == p2 || i == j)continue;

                for(int k=1;k<=3;k++){
                    if(k == p3 || j == k)continue;

                    ans = (ans + solve(r+1,n,i,j,k,dp,mod))%mod;
                }
            }
        }
        return dp[r][p1][p2][p3] = ans;
    }
    int numOfWays(int n){
        int mod = 1e9 + 7;
        vector<vector<vector<vector<int>>>> dp(n, vector<vector<vector<int>>>
        (4, vector<vector<int>>(4, vector<int>(4, -1))));

        return solve(0,n,0,0,0,dp,mod);

        
    }
};

// the second one is taulation 
class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        vector<vector<vector<vector<int>>>> dp(
            n + 1,
            vector<vector<vector<int>>>(
                4, vector<vector<int>>(4, vector<int>(4, 0))
            )
        );
        for(int p1 = 0; p1 <= 3; p1++){
            for(int p2 = 0; p2 <= 3; p2++){
                for(int p3 = 0; p3 <= 3; p3++){
                    dp[n][p1][p2][p3] = 1;
                }
            }
        }

        for (int r = n - 1; r >= 0; r--) {
            for (int p1 = 0; p1 <= 3; p1++) {
                for (int p2 = 0; p2 <= 3; p2++) {
                    for (int p3 = 0; p3 <= 3; p3++) {
                        long long ways = 0;
                        for (int i = 1; i <= 3; i++) {
                            if (i == p1) continue;
                            for (int j = 1; j <= 3; j++) {
                                if (j == p2 || j == i) continue;
                                for (int k = 1; k <= 3; k++) {
                                    if (k == p3 || k == j) continue;
                                    ways = (ways + dp[r + 1][i][j][k]) % MOD;
                                }
                            }
                        }
                        dp[r][p1][p2][p3] = ways;
                    }
                }
            }
        }

        return dp[0][0][0][0];
    }
};

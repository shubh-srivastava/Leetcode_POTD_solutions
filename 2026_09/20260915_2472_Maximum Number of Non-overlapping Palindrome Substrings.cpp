// 15th Spetember 2026

class Solution {
public:
int n;
    bool isPalindrome(int i,int j,string& s){
        while(i < j){
            if(s[i] != s[j]){
                return false;
            }
            i++;
            j--;
        }
        return true;
    }
    // int solve(int i,int j,int k,string &s,vector<vector<int>>&dp){
    //     if(i >= n || j >= n){
    //         return 0;
    //     }
    //     if(dp[i][j] != -1){
    //         return dp[i][j];
    //     }
    //     if(isPalindrome(i,j,s)){
    //         int take = 1 + solve(j+1,j+k,k,s,dp);
    //         int grow = solve(i,j+1,k,s,dp);
    //         int slide = solve(i+1,j+1,k,s,dp);
    //         return dp[i][j] = max({take,grow,slide});
    //     }
    //     int grow = solve(i,j+1,k,s,dp);
    //     int slide = solve(i+1,j+1,k,s,dp);
    //     return dp[i][j] = max(grow,slide);
    // }
    int maxPalindromes(string s, int k){
        n = s.size();
        if(k == 1){
            return n;
        }
        vector<vector<bool>>isPalin(n,vector<bool>(n,false));
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                if(isPalindrome(i,j,s)){
                    isPalin[i][j] = true;
                }
            }
        }
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        for(int i=n-1;i>=0;i--){
            for(int j=n-1;j>=0;j--){
                if(isPalin[i][j]){
                    int take = 1 + (j + k <= n ? dp[j+1][j+k] : 0);
                    int grow = dp[i][j+1];
                    int slide = dp[i+1][j+1];
                    dp[i][j] = max({take,grow,slide});
                }
                int grow = dp[i][j+1];
                int slide = dp[i+1][j+1];
                dp[i][j] = max({dp[i][j],grow,slide});
            }
        }
        return dp[0][k-1];
    }
};
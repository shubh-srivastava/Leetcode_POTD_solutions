// 10th march 2026

class Solution {
public:
    int numberOfStableArrays(int zero, int one, int limit) {
        int mod = 1e9 + 7;
        if(one < zero) swap(one, zero);
        vector<vector<int>> dp0(zero + 1, vector<int>(zero + 1)), dp1(one + 1, vector<int>(one + 2));
        
        dp0[0][0] = 1;
        for(int i = 1; i <= zero; i++) {
            for(int j = ((i / limit) + ((i % limit) > 0)); j <= i; j++) {
                dp0[i][j] = dp0[i-1][j] + dp0[i-1][j-1];
                dp0[i][j] %= mod;
                if(i > limit) dp0[i][j] += (mod - dp0[i - limit - 1][j - 1]);
                dp0[i][j] %= mod;
            }
        }
        
        dp1[0][0] = 1;
        for(int i = 1; i <= one; i++) {
            for(int j = ((i / limit) + ((i % limit) > 0)); j <= i; j++) {
                dp1[i][j] = dp1[i-1][j] + dp1[i-1][j-1];
                dp1[i][j] %= mod;
                if(i > limit) dp1[i][j] += (mod - dp1[i - limit - 1][j - 1]);
                dp1[i][j] %= mod;
            }
        }
        
        int ans = 0;
        for(int i = ((zero / limit) + ((zero % limit) > 0)); i <= zero; i++) {
            long long save = (long long)(dp0[zero][i]) * (long long)(dp1[one][i-1]);
            save %= mod;
            save += (long long)(dp0[zero][i]) * (long long)(dp1[one][i]);
            save %= mod;
            save += (long long)(dp0[zero][i]) * (long long)(dp1[one][i]);
            save %= mod;
            save += (long long)(dp0[zero][i]) * (long long)(dp1[one][i+1]);
            save %= mod;
            ans += save;
            ans %= mod;
        }
        return ans;
    }
};
// 7th September 2026

class Solution {
public:
    int distinctSubseqII(string s){
        int M = 1e9 + 7;
        vector<long long> dp(26, 0);

        for(char c : s){
            int x = c - 'a';
            long long total = 1;
            for (int i = 0; i < 26; i++) {
                total = (total + dp[i]) % M;
            }
            dp[x] = total;
        }
        long long result = 0;
        for(int i=0;i<26;i++){
            result = (result + dp[i]) % M;
        }
        return result;
    }
};
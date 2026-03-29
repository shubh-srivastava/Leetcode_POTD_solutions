// 28th feb 2026

class Solution {
public:
    int concatenatedBinary(int n){
        const int MOD = 1e9 + 7;
        long long ans = 0;
        int bitlen = 0;

        for(int i=1;i<=n;i++){
            if((i & (i-1)) == 0){
                bitlen++;
            }
            ans = ((ans << bitlen) | i) % MOD;
        }                        
        return ans;
    }
};
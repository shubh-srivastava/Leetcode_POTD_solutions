//21st feb 2026

class Solution {
public:
vector<bool>primeN;
    void solve(){
        primeN[0] = primeN[1] = false;
        for(int i=2;i*i<=32;i++){
            if(primeN[i]){
                for(int p = i*i;p<=32;p += i){
                    primeN[p] = false;
                }
            }
        }
    } 
    int countPrimeSetBits(int left, int right){
        primeN.resize(33,true);
        solve();
        int ans = 0;
        for(int i=left;i<=right;i++){
            int nb = __builtin_popcount(i);
            if(primeN[nb] == true){
                ans++;
            }
        }
        return ans;
    }
};
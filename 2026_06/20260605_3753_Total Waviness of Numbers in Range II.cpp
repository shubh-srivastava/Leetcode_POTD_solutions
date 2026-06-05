// 5th June 2026

class Solution {
public:
    vector<int> d;
    long long dp[30][30][11][11][2][2];
    long long solve(int pos, int sum, int prv2, int prv, bool small, bool nz){
        if(pos == d.size()) return sum;
        if(dp[pos][sum][prv2][prv][small][nz]!=-1){
            return dp[pos][sum][prv2][prv][small][nz];
        }
        int lim=(small?9:d[pos]);
        long long ans=0;
        for(int i=0;i<=lim;i++){
            bool nsmall = (small || i<d[pos]);
            bool nnz = nz || (i!=0);
            if(nnz){
                int nprv2 = prv;
                int nprv = i;
                int nsum = sum;
                if (prv2 != 10 && prv != 10) {
                    nsum += (prv2 < prv && prv > i);
                    nsum += (prv2 > prv && prv < i);
                }
                ans+=solve(pos+1, nsum, nprv2, nprv, nsmall, nnz);
            }
            else ans+=solve(pos+1, sum, prv2, prv, nsmall, nnz);
        }
        return dp[pos][sum][prv2][prv][small][nz]=ans;
    }
    long long count(long long x){
        if(x==0) return 0;
        d.clear();
        while(x){
            d.push_back(x%10);
            x/=10;
        }
        reverse(d.begin(),d.end());
        memset(dp,-1,sizeof(dp));
        return solve(0,0,10,10,0,0);
    }
    long long totalWaviness(long long num1, long long num2){
        return count(num2)-count(num1-1);
    }        
};
// 8th July 2026

class Solution {
public:
typedef long long ll;
int MOD = 1e9+7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries){
        int n = s.length();
        vector<int>nonZeroCount(n,0);
        vector<ll>numberUpto(n,0);
        vector<ll>digitSumUpTo(n,0);
        vector<ll>pow10(n+1,0);

        pow10[0] = 1;
        for(int i=1;i<=n;i++){
            pow10[i] = 10 * pow10[i-1] % MOD;
        }        
        nonZeroCount[0] = (s[0] == '0' ? 0 : 1);
        for(int i=1;i<n;i++){
            int digit = s[i] - '0';
            nonZeroCount[i] = nonZeroCount[i-1] + (digit == 0 ? 0 : 1);
        }
        numberUpto[0] = s[0] - '0';
        for(int i=1;i<n;i++){
            int digit = s[i] - '0';
            if(digit != 0){
                numberUpto[i] = ((numberUpto[i-1] * 10) + digit) % MOD;
            }
            else{
                numberUpto[i] = numberUpto[i-1];
            }
        }
        digitSumUpTo[0] = s[0] - '0';
        for(int i=1;i<n;i++){
            int digit = s[i] - '0';
            digitSumUpTo[i] = digitSumUpTo[i-1] + digit;
        }

        int q = queries.size();
        vector<int>result(q);

        for(int i=0;i<q;i++){
            int l  = queries[i][0];
            int r = queries[i][1];

            int startCount = (l == 0) ? 0 : nonZeroCount[l - 1];
            ll numBefore   = (l == 0) ? 0 : numberUpto[l - 1];
            int endCount = nonZeroCount[r];
            int subStrLen = endCount - startCount;

            if(subStrLen == 0){
                result[i] = 0;
                continue;
            }
            ll x   = (numberUpto[r] - (numBefore * pow10[subStrLen] % MOD) + MOD) % MOD;
            ll sum = digitSumUpTo[r] - ((l == 0) ? 0 : digitSumUpTo[l - 1]);

            result[i] = (int)((x * sum) % MOD);
        }
        return result;
    }
};
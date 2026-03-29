// 7th march 2026

class Solution {
public:
    int minFlips(string s){
        int n = s.size();
        int res = n;
        vector<int>op(2,0);

        for(int i=0;i<n;i++){
            op[(s[i] ^ i) & 1]++;
        }        

        for(int i=0;i<n;i++){
            op[(s[i] ^ i) & 1]--;
            op[(s[i] ^ (n+i)) & 1]++;
            res = min({res,op[0],op[1]});
        }
        return res;
    }
};
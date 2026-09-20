// 20th September 2026

class Solution {
public:
    int reverseDegree(string s){
        int ans = 0;
        for(int i=0;i<s.size();i++){
            int prod = ((26 - (s[i] - 'a'))*(i+1));
            ans = ans + prod;
            // cout<<ans<<endl;
        }
        return ans;
    }
};
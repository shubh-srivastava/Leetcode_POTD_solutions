// 28th September 2026

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0,curr=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                curr++;
                ans = max(curr,ans);
            }
            else if(s[i] == ')'){
                curr--;
            }
        }
        return ans;
    }
};
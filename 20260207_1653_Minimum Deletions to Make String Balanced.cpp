// 7th feb 2026

class Solution {
public:
    int minimumDeletions(string s){
        int n = s.size();
        vector<int>noofa(n,0),noofb(n,0);
        int cnt = 0;
        for(int i=0;i<n;i++){
            noofa[i] = cnt;
            if(s[i] == 'b'){
                cnt++;
            }
        }              
        cnt = 0;
        for(int i=n-1;i>=0;i--){
            noofb[i] = cnt;
            if(s[i] == 'a'){
                cnt++;
            }
        }              
        int ans = n;
        for(int i=0;i<n;i++){
            ans = min(ans,noofa[i] + noofb[i]);
        }
        return ans;          
    }
};
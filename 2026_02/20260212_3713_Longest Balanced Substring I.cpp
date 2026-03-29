//12th feb 2026 

class Solution {
public:
    int longestBalanced(string s){
        int n = s.size();
        int ans = 0;
        for(int i=0;i<n;i++){
            vector<int>freq(26,0);
            int distinct = 0;
            int maxfreq = 0;

            for(int j=i;j<n;j++){
                int idx = s[j] - 'a';
                if(freq[idx] == 0){
                    distinct++;
                }    
                freq[idx]++;
                maxfreq = max(freq[idx],maxfreq);
                
                if(maxfreq*distinct == (j-i+1)){
                    ans = max(ans,j-i+1);
                }
            }
        }        
        return ans;
    }
};
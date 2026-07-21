// 21st July 2026

class Solution {
public:
    int maxActiveSectionsAfterTrade(string s){
        int n = s.size();
        int active = 0;
        for(int i=0;i<n;i++){
            if(s[i] == '1'){
                active++;
            }
        }
        vector<int>inactive;
        int i = 0;
        while(i < n){
            if(s[i] == '0'){
                int start = i;
                while(i < n && s[i] == '0'){
                    i++;
                }
                inactive.push_back(i - start);
            }
            else{
                i++;
            }
        }
        int maxPairSum = 0;
        for(int i=1;i<inactive.size();i++){
            maxPairSum = max(inactive[i-1] + inactive[i],maxPairSum);
        }
        return maxPairSum + active;
    }
};
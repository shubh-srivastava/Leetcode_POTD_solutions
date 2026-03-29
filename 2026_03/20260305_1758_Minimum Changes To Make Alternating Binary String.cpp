// 5th Mrach 2026

class Solution {
public:
    int minOperations(string s){
        int n = s.size();
        char curr0 = '0';
        char curr1 = '1';
        int r1=0,r2=0;
        for(int i=0;i<n;i++){
            if(s[i] != curr0){
                r1++;
            }
            if(s[i] != curr1){
                r2++;
            }
            curr0 = (curr0 == '0') ? '1' : '0';
            curr1 = (curr1 == '0') ? '1' : '0';
        }        
        return min(r1,r2);
    }
};
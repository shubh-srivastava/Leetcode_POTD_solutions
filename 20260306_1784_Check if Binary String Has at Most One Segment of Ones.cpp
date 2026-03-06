// 6th march 2026

class Solution {
public:
    bool checkOnesSegment(string s){
        bool ch = false;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                ch = true;
            }
            if(ch == true && s[i] == '1'){
                return false;
            }
        }        
        return true;
    }
};
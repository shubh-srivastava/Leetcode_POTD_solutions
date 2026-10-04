// 4th October 2026

class Solution {
public:
    bool checkValidString(string s){
        int minc=0,maxc=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                minc++;
                maxc++;
            }
            else if(s[i] == ')'){
                maxc--;
                minc--;
            }
            else if(s[i] == '*'){
                minc--;
                maxc++;
            }
            if(maxc < 0){
                return false;
            }
            if(minc < 0){
                minc = 0;
            }
        }    
        return (minc == 0);
    }
};
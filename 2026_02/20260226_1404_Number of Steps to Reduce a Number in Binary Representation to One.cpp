// 26th feb 2026

class Solution {
public:
    int numSteps(string s){
        if(s == "1"){
            return 0;
        }
        int steps = 0, carry = 0;
        int n = s.size();
        for (int i = n-1;i>0;i--){
            if((s[i] & 1) + carry == 1){
                steps += 2;
                carry = 1;
            } 
            else{
                steps += 1;
            }
        }
        return steps + carry;
    }
};
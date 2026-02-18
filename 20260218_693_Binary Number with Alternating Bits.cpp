// 18th feb 2026

class Solution {
public:
    bool hasAlternatingBits(int n){
        int lastb = -1;
        while(n > 0){
            int bit = n & 1;
            if(bit == lastb){
                return false;
            }
            lastb = bit;
            n = n >> 1;
        } 
        return true;      
    }
};
// 8th September 2026

class Solution {
public:
    int countCommas(int n){
        if(n < 1000){
            return 0;
        }
        return (n - 1000) + 1;
        
    }
};
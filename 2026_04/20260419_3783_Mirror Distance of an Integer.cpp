// 18th April 2026

class Solution {
public:
    int mirrorDistance(int n){
        int dumn = n;
        int revn = 0;
        while(n > 0){
            revn = revn*10;
            revn += n%10;
            n = n/10;
        }        

        return abs(revn - dumn);
    }
};
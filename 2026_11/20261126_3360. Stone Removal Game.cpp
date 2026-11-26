// 26th November 2026

class Solution {
public:
    bool canAliceWin(int n){
        int rem = 10;
        while(rem > 0){
            if(rem > n){
                if(rem%2 == 0){
                    return false;
                }
                else{
                    return true;
                }
            }
            n = n - rem;
            rem--;
        }
        return true;
    }
};
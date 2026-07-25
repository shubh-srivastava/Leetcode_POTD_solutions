// 25th July 2026

class Solution {
public:
    int maxProduct(int n){
        int dig1 = 0;
        int dig2 = 0;

        while(n > 0){
            int dig = n%10;
            if(dig > dig1){
                dig2 = dig1;
                dig1 = dig;
            }
            else if(dig > dig2){
                dig2 = dig;
            }
            n = n / 10;
        }        
        return dig1*dig2;
    }
};
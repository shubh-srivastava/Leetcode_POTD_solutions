// 6th August 2026

class Solution {
public:
    int productOfDigits(int num){
        int prod = 1;

        while(num){
            prod *= num % 10;
            num /= 10;
        }             
        return prod;
    }
    int smallestNumber(int n, int t){
        while(productOfDigits(n)%t != 0){
            n++;
        }
        return n;
    }
};
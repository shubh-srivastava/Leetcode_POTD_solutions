// 23rd August 2026

class Solution {
public:
    bool sumGame(string num){
        int first = 0;
        int second = 0;
        int firstq = 0;
        int secondq = 0;
        int n = num.size();
        for(int i=0;i<n/2;i++){
            if(num[i] == '?'){
                firstq++;
            }
            else{
                first += (int)(num[i] - '0');
            }
            if(num[n-i-1] == '?'){
                secondq++;
            }
            else{
                second += (int)(num[n-i-1] - '0');
            }
        }      
        if(firstq == secondq){
            return first != second;
        }

        int diff = first - second;
        int qdiff = firstq - secondq;

        if(qdiff % 2 != 0){
            return true;
        }
        return diff != -9 * qdiff / 2;
    }
};
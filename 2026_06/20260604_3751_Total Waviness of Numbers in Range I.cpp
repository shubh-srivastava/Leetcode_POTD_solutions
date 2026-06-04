// 4th July 2026

class Solution {
public:
    int totalWaviness(int num1, int num2){
        int total = 0;
        for(int i=num1;i<=num2;i++){
            if(i < 100){
                continue;
            }
            string str = to_string(i);
            int n = str.size();
            for(int j=1;j<n-1;j++){
                if(str[j] > str[j+1] && str[j] > str[j-1]){
                    total++;
                }
                else if(str[j] < str[j+1] && str[j] < str[j-1]){
                    total++;
                }
            }
        }         
        return total;
    }
};
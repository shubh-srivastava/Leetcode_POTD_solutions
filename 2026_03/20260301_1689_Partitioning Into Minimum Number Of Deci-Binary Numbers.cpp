// 1st march 2026

class Solution {
public:
    int minPartitions(string s){
        int maxd = 0;
        for(char c : s){
            maxd = max(maxd,c-'0');
        }        
        return maxd;
    }
};
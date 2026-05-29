// 29th May 2026

class Solution {
public:
    int minElement(vector<int>& nums){
        int mine = 1e5;
        for(int i : nums){
            int sum = 0;
            while(i > 0){
                sum += i%10;
                i = i/10;
            }
            mine = min(mine,sum);
        }        
        return mine;
    }
};
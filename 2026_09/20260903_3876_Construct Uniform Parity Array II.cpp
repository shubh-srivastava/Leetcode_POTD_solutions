// 3rd September 2026

class Solution {
public:
    bool uniformArray(vector<int>& nums1){
        int smallE = INT_MAX;
        int smallO = INT_MAX;

        for(int i : nums1){
            if(i % 2 == 0){
                smallE = min(smallE, i);
            } 
            else{
                smallO = min(smallO, i);
            }
        }
        if(smallE == INT_MAX || smallO == INT_MAX){
            return true;
        }
        return smallE > smallO;
    }
};
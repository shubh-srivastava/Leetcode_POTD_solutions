// 1st FEB 2026

class Solution {
public:
    int minimumCost(vector<int>& nums){
        int min2=1e9;
        int min3=1e9;
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= min2){
                min3 = min2;
                min2 = nums[i];
            }
            else if(nums[i] <= min3){
                min3 = nums[i];
            }
        }
        return nums[0] + min2 + min3;
    }
};
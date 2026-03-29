// 3rd FEB 2026

class Solution {
public:
    bool isTrionic(vector<int>& nums){
        int i=0;
        int n = nums.size();
        int b1 = false,b2=false,b3=false;
        while(i + 1<n && nums[i] < nums[i+1]){
            i++;
            b1 = true;
        }   
        while(i+1 <n && nums[i] > nums[i+1] && b1){
            i++;
            b2 = true;
        }
        while(i+1 < n && nums[i] < nums[i+1] && b2){
            i++;
            b3 = true;
        }
        if(i == n-1 && b1 && b2 && b3)return true;
        return false;
        
    }
};
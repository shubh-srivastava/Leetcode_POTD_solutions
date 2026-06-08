// 8th June 2026

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot){
        int j = 0;
        int n = nums.size();
        vector<int>ans(n);

        for(int i=0;i<n;i++){
            if(nums[i] < pivot){
                ans[j++] = nums[i];
            }
        }    
        for(int i=0;i<n;i++){
            if(nums[i] == pivot){
                ans[j++] = nums[i];
            }
        }   
        for(int i=0;i<n;i++){
            if(nums[i] > pivot){
                ans[j++] = nums[i];
            }
        } 
        return ans; 
    }
};
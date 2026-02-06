// 6th FEB 2026

class Solution {
public:
    int minRemoval(vector<int>& nums, int k){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int i=0,j=0;      
        int step = INT_MAX;
        while(j<n){
            while(j < n && nums[j] <= 1LL* k * nums[i]){
                step = min(step,n-(j-i+1));
                j++;
            }
            i++;
        }  
        return step;
    }
};
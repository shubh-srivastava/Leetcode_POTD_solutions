// 9th June 2026

class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k){
        // long long maxe = *max_element(nums.begin(),nums.end());
        // long long mine = *min_element(nums.begin(),nums.end());
        return ((long long)*max_element(nums.begin(),nums.end()) - (long long)*min_element(nums.begin(),nums.end())) * k;  
    }      
};
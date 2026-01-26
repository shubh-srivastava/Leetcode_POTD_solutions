// 25TH JAN 2026

class Solution {
public:
    int minimumDifference(vector<int>& nums, int k){
        if(k == 1)return 0;
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int r=k-1,l=0;
        int minD = INT_MAX;
        while(r < n){
            minD = min(minD,nums[r] - nums[l]);
            r++;
            l++;
        }
        return minD;
    }
};
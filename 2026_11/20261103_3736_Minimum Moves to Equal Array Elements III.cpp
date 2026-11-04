// 3rd November 2026

class Solution {
public:
    int minMoves(vector<int>& nums){
        int maxe = *max_element(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ans += maxe - nums[i];
        }
        return ans;
    }
};
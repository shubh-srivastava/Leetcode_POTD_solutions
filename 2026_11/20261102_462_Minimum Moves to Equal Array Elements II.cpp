// 2nd November 2026

class Solution {
public:
    int minMoves2(vector<int>& nums){
        sort(nums.begin(),nums.end());
        int n = nums.size();
        int avg = (n%2 == 0) ? nums[(n-1) / 2] : nums[n/2];
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += abs(nums[i] - avg);
        }
        return ans;
    }
};
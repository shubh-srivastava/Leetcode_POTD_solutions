// 6th June 2026

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums){
        long long lsum = 0;
        long long rsum = accumulate(nums.begin(),nums.end(),0LL);

        vector<int> ans(nums.size());
        for(int i=0;i<nums.size();i++){
            rsum -= nums[i];
            ans[i] = abs(lsum - rsum);
            lsum += nums[i];
        }
        return ans;
    }
};
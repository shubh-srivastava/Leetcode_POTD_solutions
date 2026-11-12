// 12th November 2026

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums){
        int maxlen = 1;
        int curr = 1;
        int n = nums.size();
        for(int i=1;i<n;i++){
            if(nums[i] > nums[i-1]){
                curr++;
            }
            else{
                curr = 1;
            }
            maxlen = max(maxlen,curr);
        }
        curr = 1;
        for(int i=n-1;i>=1;i--){
            if(nums[i] < nums[i-1]){
                curr++;
            }
            else{
                curr = 1;
            }
            maxlen = max(maxlen,curr);
        }
        return maxlen;
    }
};
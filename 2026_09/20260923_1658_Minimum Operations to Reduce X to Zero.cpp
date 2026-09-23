// 23rd September 2026

class Solution {
public:
    int minOperations(vector<int>& nums, int x){
        int total = accumulate(nums.begin(),nums.end(),0);
        if(x > total){
            return -1;
        }
        int sum = total - x;
        int maxlen = -1;
        int l=0,r=0,curr=0;
        int n = nums.size();
        while(r < n){
            curr+=nums[r];
            while(curr > sum && l <= r){
                curr -= nums[l];
                l++;
            }
            if(curr == sum){
                maxlen = max(maxlen,r-l+1);
            }
            r++;
        }       
        if(maxlen == -1){
            return -1;
        }
        return n - maxlen; 
    }
};
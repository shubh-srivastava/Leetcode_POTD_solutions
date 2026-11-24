// 24th November 2026

class Solution {
public:
    int maxLength(vector<int>& nums){
        int best = 2;
        int left = 0;
        int prod = 1;
        for(int right=0;right<nums.size();right++){
            int x = nums[right];
            while(gcd(prod,x) > 1){
                prod /= nums[left++];
            }
            prod *= x;
            best = max(best,right - left + 1);
        }
        return best;
    }
};
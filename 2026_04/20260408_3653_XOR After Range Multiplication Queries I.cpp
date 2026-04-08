// 8th April 2026

class Solution {
public:
    const int mod=1000000007;
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries){
        for(auto &t:queries){
            int l = t[0];
            int r = t[1];
            int k = t[2];
            int v = t[3];
            int idx = l;
            while(idx <= r){
                long long temp = nums[idx];
                nums[idx] = (temp*v)%mod;
                idx += k;
            }
        }
        int ans = 0;
        for(int num : nums){
            ans ^=num;
        }
        return ans;
    }
};
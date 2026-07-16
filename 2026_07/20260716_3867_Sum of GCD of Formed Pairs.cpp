// 16th July 2026

class Solution {
public:
    long long gcdSum(vector<int>& nums){
        int n = nums.size();
        int mx = -1;
        vector<int>prefixGcd;
        for(int i=0;i<n;i++){
            mx = max(mx,nums[i]);
            prefixGcd.push_back(__gcd(nums[i],mx));
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        long long res = 0;
        for(int i=0;i<n/2;i++){
            res += __gcd(prefixGcd[i],prefixGcd[n-i-1]);
        }
        return res;
        
    }
};
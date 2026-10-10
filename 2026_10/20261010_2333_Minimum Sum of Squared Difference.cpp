// 10th October 2026

class Solution {
public:
    long long required(int mid,vector<int>&diff){
        long long ops = 0;
        for(int d : diff){
            if(d > mid){
                ops += d - mid;
            }
        }
        return ops;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2,int k1, int k2){
        int n = nums1.size();
        long long k = (long long)k1 + k2;

        vector<int> diff(n);
        int maxDiff = 0;
        long long total = 0;

        for(int i=0;i<n;i++){
            diff[i] = abs(nums1[i] - nums2[i]);
            maxDiff = max(maxDiff, diff[i]);
            total += diff[i];
        }

        if(k >= total){
            return 0;
        }

        int low = 0, high = maxDiff;

        while(low < high){
            int mid = low + (high - low) / 2;

            if(required(mid,diff) <= k){
                high = mid;
            } 
            else{
                low = mid + 1;
            }
        }

        int level = low;
        long long used = required(level,diff);
        long long remaining = k - used;

        long long ans = 0;

        for(int d : diff){
            long long finalDiff = min(d, level);
            ans += finalDiff * finalDiff;
        }
        ans -= remaining * (2LL * level - 1);

        return ans;
    }
};

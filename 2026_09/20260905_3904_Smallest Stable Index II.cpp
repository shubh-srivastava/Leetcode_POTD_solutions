// 5th September 2026

class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k){
        int n = nums.size();
        vector<int>limax(n);
        vector<int>irmin(n);

        limax[0] = nums[0];
        irmin[n-1] = nums[n-1];
        for(int i=1;i<n;i++){
            limax[i] = max(limax[i-1],nums[i]);
        }        
        for(int i=n-2;i>=0;i--){
            irmin[i] = min(irmin[i+1],nums[i]);
        }

        for(int i=0;i<n;i++){
            if(limax[i] - irmin[i] <= k){
                return i;
            }
        }
        return -1;
    }
};
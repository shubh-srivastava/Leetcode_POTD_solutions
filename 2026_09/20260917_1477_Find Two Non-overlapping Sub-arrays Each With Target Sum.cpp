// 17th September 2026

class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target){
        int n = arr.size();
        int l=0;
        int sum = 0;
        int minlen = INT_MAX;
        vector<int>prefix(n,-1);
        for(int r=0;r<n;r++){
            sum += arr[r];
            while(sum > target && l <= r){
                sum -= arr[l];
                l++;
            }
            if(sum == target){
                minlen = min(minlen,r-l+1);
            }
            if(minlen == INT_MAX){
                prefix[r] = -1;
            }
            else{
                prefix[r] = minlen;
            }
        }
        int r=n-1;
        l=n-1,minlen = INT_MAX;
        sum = 0;
        vector<int>suffix(n,-1);
        for(l=n-1;l>=0;l--){
            sum += arr[l];
            while(sum > target && r >= l){
                sum -= arr[r];
                r--;
            }
            if(sum == target){
                minlen = min(minlen,r-l+1);
            }
            if(minlen == INT_MAX){
                suffix[l] = -1;
            }
            else{
                suffix[l] = minlen;
            }
        }
        int ans = 1e6;
        for(int i=0;i<n-1;i++){
            if(prefix[i] != -1 && suffix[i+1] != -1){
                ans = min(ans,prefix[i] + suffix[i+1]);
            }
        }
        if(ans == 1e6){
            return -1;
        }
        return ans;
    }
};
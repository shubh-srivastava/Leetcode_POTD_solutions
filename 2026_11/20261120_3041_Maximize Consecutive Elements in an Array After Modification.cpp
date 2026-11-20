// 20th November 2026

class Solution {
public:
int n;
vector<vector<int>>dp;
    int find(vector<int>&nums,int i,int val){
        int j = lower_bound(nums.begin() + i,nums.end(),val) - nums.begin();
        if(j < n && nums[j] == val){
            return j;
        }
        return -1;
    }

    int maxSelectedElements(vector<int>& nums){
        n = nums.size();
        sort(nums.begin(),nums.end());
        dp.assign(n+1,vector<int>(2,0));
        int result = 1;

        for(int i=n-1;i>=0;i--){
            for(int inc = 0;inc <= 1;inc++){
                int curr = nums[i] + inc;
                int len = 1;
                int j = find(nums,i+1,curr+1);
                if(j != -1){
                    len = max(len,1 + dp[j][0]);
                }

                j = find(nums,i+1,curr);
                if(j != -1){
                    len = max(len,1 + dp[j][1]);
                }
                dp[i][inc] = len;
                result = max(result,len);
            }
        }                        
        return result;
    }
};
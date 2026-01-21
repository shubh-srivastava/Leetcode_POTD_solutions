// 21ST JAN 2026
class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums){
        int n = nums.size();
        vector<int>ans(n,-1);

        for(int i=0;i<n;i++){
            for(int j=0;j<32;j++){
                if((nums[i] & (1<<j)) > 0){
                    continue;
                }
                if(j==0)break;
                int x = nums[i]^(1<<(j-1));
                ans[i] = x;
                break;
            }
        }   
        return ans;        
    }
};
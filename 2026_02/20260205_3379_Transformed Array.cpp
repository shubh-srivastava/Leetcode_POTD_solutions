// 5th FEB 2026

class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(nums[i] > 0){
                ans[i] = nums[(i + nums[i]%n)%n];
                //cout<<i<<" "<<(i + nums[i])%n<<endl;
            }
            if(nums[i] < 0){
                ans[i] = nums[((i + nums[i]%n) + n)%n];
                //cout<<i<<" "<<(i + nums[i])%n<<endl;
            }
            if(nums[i] == 0){
                ans[i] = nums[i];
                //cout<<i<<" "<<endl;
            }
        }
        return ans;
    }
};
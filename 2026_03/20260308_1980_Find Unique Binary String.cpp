// 8th march 2026

class Solution {
public:
    string findDifferentBinaryString(vector<string>& nums){
        string ans = nums[0];
        int n = nums.size();
        for(int i=0;i<n;i++){
            if(ans[i] == nums[i][i]){
                if(ans[i] == '1'){
                    ans[i] = '0';
                }
                else{
                    ans[i] = '1';
                }
            }
        }        
        return ans;
    }
};
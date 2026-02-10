// 10th feb 2026

class Solution {
public:
    int longestBalanced(vector<int>& nums){
        
        int n = nums.size();
        int ans= 0;
        for(int i=0;i<n;i++){
            unordered_map<int,int>mpo;
            unordered_map<int,int>mpe;
            for(int j=i;j<n;j++){
                if(nums[j]&1){
                    mpo[nums[j]]++;
                }
                else{
                    mpe[nums[j]]++;
                }
                if(mpe.size() == mpo.size()){
                    ans = max(ans,j-i+1);
                }
            }            
        } 
        return ans;      
    }
};
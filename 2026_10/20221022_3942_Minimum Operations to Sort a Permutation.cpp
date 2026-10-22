// 22nd October 2026

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        while(start<n && nums[start]!=0){
            start++;
        }
        for(int i=0;i<n;i++){
            if(i!=nums[(start+i)%n]){
                break;
            }
            else if(i==n-1){
                return min(start,n-start+2);
            }
        }
        start=0;
        while(start<n && nums[start]!=n-1){
            start++;
        }
        for(int i=0;i<n;i++){
            if(n-1-i!=nums[(start+i)%n]){
                return -1;
            }
            else if(i==n-1) return min(1+n-start,start+1);
        }
        return -1;
    }
};
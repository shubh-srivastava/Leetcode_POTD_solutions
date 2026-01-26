//4th JAN 2026
class Solution {
public:
    int divSum(int n){
        int ans = 0;
        int cnt = 0;
        for(int i=1;i*i<=n;i++){
            if(n%i==0){
                if(i*i == n){
                    cnt++;
                    ans += i;
                }
                else{
                    cnt=cnt+2;
                    ans += i + n/i;
                }
            }
        }
        if(cnt < 4)return 0;
        if(cnt > 4)return 0;
        return ans;
    }
    int sumFourDivisors(vector<int>& nums){
        int ans = 0;
        for(int i=0;i<nums.size();i++){
            ans += divSum(nums[i]);
        }
        return ans;
        
    }
};
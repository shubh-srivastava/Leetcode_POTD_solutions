// 19th June 2026

class Solution {
public:
    int largestAltitude(vector<int>& gain){
        int ans=0,sum=0;
        for(int i : gain){
            sum+=i;
            int d = sum - ans;
            ans += d & ~(d >> 0x1F);
        }
        return ans;
        
    }
};
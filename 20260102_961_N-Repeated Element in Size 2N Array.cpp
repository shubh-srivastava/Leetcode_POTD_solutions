// 2nd january 2026
class Solution {
public:
    int repeatedNTimes(vector<int>& nums){
        unordered_map<int,int>mp;

        for(int i : nums){
            mp[i]++;
        }        
        int ans = 0;
        int freq = nums.size()/2;
        for(auto it : mp){
            if(it.second == freq){
                return it.first;
            }
        }
        return -1;
    }
};
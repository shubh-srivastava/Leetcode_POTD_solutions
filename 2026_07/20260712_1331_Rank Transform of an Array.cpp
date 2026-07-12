// 12th July 2026

class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr){
        int n = arr.size();
        vector<int>nums = arr;
        sort(nums.begin(),nums.end());

        unordered_map<int,int>mp;
        int numQ = 0;
        for(int i=0;i<n;i++){
            if(mp.find(nums[i]) == mp.end()){
                numQ++;
                mp[nums[i]] = numQ;
            }
        }

        for(int i=0;i<n;i++){
            arr[i] = mp[arr[i]];
        }
        return arr;
    }
};
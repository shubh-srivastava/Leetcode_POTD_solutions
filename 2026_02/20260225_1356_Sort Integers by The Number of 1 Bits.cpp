// 25th feb 2026

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr){
        map<int,vector<int>>mp;
        for(int i=0;i<arr.size();i++){
            int b = __builtin_popcount(arr[i]);
            mp[b].push_back(arr[i]);
        }        
        for(auto& it : mp){
            sort(it.second.begin(),it.second.end());
        }
        vector<int>ans;
        for(auto& it : mp){
            int m = it.second.size();
            for(int i=0;i<m;i++){
                ans.push_back(it.second[i]);
            }
        }
        return ans;
    }
};
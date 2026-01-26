// 26th JAN 2026

class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr){
        sort(arr.begin(),arr.end());

        vector<vector<int>>ans;
        int n = arr.size();
        int minD = INT_MAX;
        for(int i=1;i<n;i++){
            int diff = arr[i] - arr[i-1];

            if(diff < minD){
                ans.clear();
                ans.push_back({arr[i-1],arr[i]});
                minD = diff;
            }
            else if(diff == minD){
                ans.push_back({arr[i-1],arr[i]});
            }
        }
        return ans;
        
    }
};
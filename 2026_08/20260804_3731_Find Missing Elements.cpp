// 4th August 2026

class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums){
        unordered_set<int> seen(nums.begin(), nums.end());
        int mine = *min_element(nums.begin(), nums.end());
        int maxe = *max_element(nums.begin(), nums.end());

        vector<int> ans;
        for(int i =mine;i<=maxe;i++){
            if (!seen.count(i)) {
                ans.push_back(i);
            }
        }
        return ans;
    }
};
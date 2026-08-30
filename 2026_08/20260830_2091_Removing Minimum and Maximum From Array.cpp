// 30th August 2026

class Solution {
public:
    int minimumDeletions(vector<int>& nums){
        int n = nums.size();

        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        int left = min(mini, maxi) + 1;
        int right = n - max(mini, maxi);

        int bothLeft = max(mini, maxi) + 1;
        int bothRight = n - min(mini, maxi);

        int oneLeftOneRight = left + right;

        return min({bothLeft, bothRight, oneLeftOneRight});
    }
};
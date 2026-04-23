// 23rd April 2026

class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mp;

        // group indices
        for (int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }

        vector<long long> ans(n);

        for (auto &p : mp) {
            vector<int> &lst = p.second;
            int size = lst.size();

            // prefix sum
            vector<long long> prefix(size);
            prefix[0] = lst[0];
            for (int i = 1; i < size; i++) {
                prefix[i] = prefix[i - 1] + lst[i];
            }

            for (int i = 0; i < size; i++) {
                long long idx = lst[i];

                long long sumLeft = (i > 0) ? prefix[i - 1] : 0;
                long long sumRight = prefix[size - 1] - prefix[i];

                long long countLeft = i;
                long long countRight = size - i - 1;

                long long left = idx * countLeft - sumLeft;
                long long right = sumRight - idx * countRight;

                ans[idx] = left + right;
            }
        }

        return ans;
    }
};

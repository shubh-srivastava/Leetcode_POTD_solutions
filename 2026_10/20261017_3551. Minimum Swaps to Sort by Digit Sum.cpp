// 17th October 2026

class Solution {
public:
    int f(int x) {
        int digitSum = 0;
        while (x > 0) {
            digitSum += x % 10; 
            x /= 10;              
        }
        return digitSum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
      
        vector<pair<int, int>> digitSumPairs(n);
        for (int i = 0; i < n; ++i) {
            digitSumPairs[i] = {f(nums[i]), nums[i]};
        }
      
        sort(digitSumPairs.begin(), digitSumPairs.end());
      
        unordered_map<int, int> valueToTargetIndex;
        for (int i = 0; i < n; ++i) {
            valueToTargetIndex[digitSumPairs[i].second] = i;
        }
      
        vector<bool> visited(n, false);
      

        int cycleCount = 0;
      
        for (int i = 0; i < n; ++i) {
            if (!visited[i]) {
                cycleCount++;
              
                int currentIndex = i;
                while (!visited[currentIndex]) {
                    visited[currentIndex] = true;
                    currentIndex = valueToTargetIndex[nums[currentIndex]];
                }
            }
        }
      
        return n - cycleCount;
    }
};

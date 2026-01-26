// 23 December 2025
class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events){
        sort(events.begin(),events.end());

        vector<vector<int>> endSorted = events;
        sort(endSorted.begin(), endSorted.end(),
             [](auto &a, auto &b) {
                 return a[1] < b[1];
             });

        int ans = 0;
        int j = 0;
        int bestEndedValue = 0;

        for (auto &e : events) {
            int start = e[0], value = e[2];
            while (j < endSorted.size() && endSorted[j][1] < start) {
                bestEndedValue = max(bestEndedValue, endSorted[j][2]);
                j++;
            }
            ans = max(ans, value + bestEndedValue);
        }

        return ans;
    }
};
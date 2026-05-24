// 24th May 2026

class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> t(n, 1);
        vector<pair<int, int>> vec;
        for(int i = 0; i < n; i++){
            vec.push_back({arr[i], i});
        }
        sort(begin(vec), end(vec));

        for (auto& it : vec){
            int val = it.first;
            int i = it.second;
            for(int j = i-1;j>=max(0, i - d);j--){
                if (arr[j] >= arr[i]){
                    break;
                }
                t[i] = max(t[i], 1 + t[j]);
            }
            for (int j = i+1;j<=min(n - 1, i + d);j++){
                if(arr[j] >= arr[i]){
                    break;
                }
                t[i] = max(t[i], 1 + t[j]);
            }
        }

        return *max_element(begin(t), end(t));
    }
};
// 31st July 2026

class Solution {
public:
    int minimumPushes(string word) {
        vector<int>freq(26,0);
        for(char c : word){
            freq[c - 'a']++;
        }
        sort(freq.begin(),freq.end());
        int ans = 0;
        for(int i=25;i>=0&&freq[i] > 0;i--){
            ans += freq[i] * (((25-i)/8) + 1);
        }
        return ans;
    }
};
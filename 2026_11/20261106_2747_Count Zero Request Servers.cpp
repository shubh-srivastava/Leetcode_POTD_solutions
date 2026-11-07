// 6th November 2026

class Solution {
public:
    // static bool comp(vector<int>&v1,vector<int>&v2){
    //     return v1[1] < v2[1];
    // }
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries){
        auto comp = [](vector<int>&v1,vector<int>&v2){
            return v1[1] < v2[1];
        };
        int m = logs.size();
        sort(logs.begin(),logs.end(),comp);
        int q = queries.size();
        vector<int>result(q);

        vector<pair<int,int>> timeIndex(q);
        for (int i = 0; i < q; i++) 
            timeIndex[i] = {queries[i], i};

        sort(timeIndex.begin(), timeIndex.end());

        unordered_map<int,int> mp;
        int i = 0, j = 0;
        for(auto [curtime, ind] : timeIndex){
            int start = curtime - x;
            int end   = curtime;

            while(j < m && logs[j][1] <= end){
                mp[logs[j][0]]++;
                j++;
            }

            while(i < m && logs[i][1] < start){
                mp[logs[i][0]]--;
                if (mp[logs[i][0]] == 0) 
                    mp.erase(logs[i][0]);
                
                i++;
            }
            result[ind] = n - mp.size();
        }

        return result;
    }
};
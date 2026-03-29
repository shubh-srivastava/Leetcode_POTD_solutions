// 30th JAN 2026

class Solution {
public:
    void dijikstra(int st,vector<vector<pair<int,int>>> &adj,vector<vector<long long>>&dis){
        dis[st][st] = 0;
        set<pair<int,int>>s;

        s.insert({0,st});
        while(!s.empty()){
            auto it = s.begin();
            int node = it->second;
            s.erase(it);

            for(auto i : adj[node]){
                int ne = i.second;
                int wt = i.first;
                if(dis[st][ne] > dis[st][node]+wt){
                    dis[st][ne] = dis[st][node]+wt;
                    s.insert({dis[st][ne],ne});
                }
            }
        }
    }
    long long minimumCost(string src, string tar, vector<string>& org, vector<string>& chn, vector<int>& cost){
        int n = 0;
        map<string,int>mp;
        for(int i=0;i<org.size();i++){
            if(mp.find(org[i]) == mp.end()){
                mp[org[i]] = n++;
            }
            if(mp.find(chn[i]) == mp.end()){
                mp[chn[i]] = n++;
            }
        }

        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<org.size();i++){
            adj[mp[org[i]]].push_back({cost[i],mp[chn[i]]});
        }

        vector<vector<long long>>dis(n,vector<long long>(n,1e18));
        for(int i=0;i<n;i++){
            dijikstra(i,adj,dis);
        }

        unordered_set<int>lens;
        for(string s : org){
            lens.insert(s.size());
        }

        int m = src.size();
        vector<long long>dp(m+1,1e18);
        dp[m] = 0;

        for(int i=m-1;i>=0;i--){
            // no operation
            if(src[i] == tar[i]){
                dp[i] = dp[i+1];
            }

            // substring operation
            for(int len : lens){
                int j = i + len -1;
                if( j>= m){
                    continue;
                }
                string from = src.substr(i,len);
                string to = tar.substr(i,len);
                if(mp.find(from) == mp.end() || mp.find(to) == mp.end()){
                    continue;
                }
                long long c = dis[mp[from]][mp[to]];
                if(c < 1e18){
                    dp[i] = min(dp[i],c + dp[j+1]);
                }
            }
        }
        return dp[0] >= 1e18 ? -1 : dp[0];

    }
};
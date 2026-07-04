// 4th June 2026

class Solution {
public:
    void dfs(int node,unordered_map<int,vector<pair<int,int>>>&adj,vector<bool>&vis,int &res){
        vis[node] = true;

        for(auto &P : adj[node]){
            int v = P.first;
            int d = P.second;
            res = min(res,d);
            if(!vis[v]){
                dfs(v,adj,vis,res);
            }
        }

    }
    int minScore(int n, vector<vector<int>>& roads){
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &vec : roads){
            adj[vec[0]].push_back({vec[1],vec[2]});
            adj[vec[1]].push_back({vec[0],vec[2]});
        }

        vector<bool>vis(n,false);
        int res = INT_MAX;
        dfs(1,adj,vis,res);

        return res;        
    }
};
// 11th June 2026

class Solution {
public:
    int maxd;
    void dfs(int node,int par,int d,vector<vector<int>>&adj){
        maxd = max(maxd,d);
        for(int i : adj[node]){
            if(i != par){
                dfs(i,node,d+1,adj);
            }
        }
    }
    long long modPow(long long a,long long b, long long MOD){
        long long res = 1;
        while(b){
            if (b & 1) res = res * a % MOD;
            a = a * a % MOD;
            b >>= 1;
        }
        return res;
    }
    int assignEdgeWeights(vector<vector<int>>& edges){
        int MOD = 1e9+7;
        int n = edges.size() + 1;
        vector<vector<int>>adj(n+1);
        for(vector<int> edge : edges){
            int u = edge[0];
            int v = edge[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        dfs(1,-1,0,adj);

        return modPow(2,maxd-1,MOD);
    }
};
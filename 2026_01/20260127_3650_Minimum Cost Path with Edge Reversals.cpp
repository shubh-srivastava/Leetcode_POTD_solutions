// 27th JAN 2026

class Solution {
public:
    int minCost(int n, vector<vector<int>>& edges){
        // vecor<int>sw(n,0);
        vector<vector<pair<int,int>>>adj(n);

        for(auto it : edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],2*it[2]});
        }
        vector<int>dist(n,1e9);
        set<pair<int,int>>st;
        st.insert({0,0});
        dist[0] = 0;
        while(!st.empty()){
            auto it = st.begin();
            int d = it->first;
            int u = it->second;
            st.erase(it);

            for(auto i : adj[u]){
                if(d + i.second < dist[i.first]){
                    dist[i.first] = d + i.second;
                    st.insert({d + i.second,i.first});
                }
            }
        }
        if(dist[n-1] == 1e9){
            return -1;
        }        
        return dist[n-1];
        
    }
};
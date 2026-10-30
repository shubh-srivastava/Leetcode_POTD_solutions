// 30th October 2026

class Solution {
public:
typedef tuple<int,int,int> T;

    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k){
        unordered_map<int,vector<vector<int>>>adj;
        for(auto &edge : edges){
            adj[edge[0]].push_back({edge[1],edge[2]});
        }                

        vector<vector<int>>result(n,vector<int>(k+1,INT_MAX));

        priority_queue<T,vector<T>,greater<T>>pq;

        result[0][1] = 0;
        pq.push({0,0,1});

        while(!pq.empty()){
            auto [d,node,count] = pq.top();
            pq.pop();

            if(d > result[node][count]){
                continue;
            }
            if(node == n-1){
                return d;
            }

            for(auto & vec : adj[node]){
                int adjNode = vec[0];
                int wt = vec[1];
                int newCount = (labels[adjNode] == labels[node]) ? count + 1 : 1;
                if(newCount > k){
                    continue;
                }
                int newDist = d + wt;
                if(newDist < result[adjNode][newCount]){
                    result[adjNode][newCount] = newDist;
                    pq.push({newDist,adjNode,newCount});
                }
            }
        }
        return -1;
    }
};
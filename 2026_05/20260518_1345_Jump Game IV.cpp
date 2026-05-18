// 18th May 2026

class Solution {
public:
    int minJumps(vector<int>& arr){
        int n = arr.size();
        unordered_map<int,vector<int>>mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        vector<int>vis(n,0);
        queue<pair<int,int>>q;
        vis[0] = 1;
        q.push({0,0});
        while(!q.empty()){
            int node = q.front().first;
            int dist = q.front().second;
            q.pop();
            // vis[node]=1;
            if(node == n-1){
                return dist;
            }
            for(int i : mp[arr[node]]){
                if(!vis[i]){
                    vis[i] = 1;
                    q.push({i,dist+1});
                }
            }
            mp[arr[node]].clear();
            int left = node-1;
            int right = node+1;
            if(left >= 0 && !vis[left]){
                vis[left] = 1;
                q.push({left,dist+1});
            }
            if(right <= n-1 && !vis[right]){
                vis[right] = 1;
                q.push({right,dist+1});
            }
        }
        return -1;
    }
};
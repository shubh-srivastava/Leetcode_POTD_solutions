// 29th JAN 2026
class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& org, vector<char>& chn, vector<int>& cost){
        // 
        vector<vector<int>>dist(26,vector<int>(26,-1));
        for(int i=0;i<org.size();i++){
            if(dist[org[i]-'a'][chn[i]-'a'] == -1){
                dist[org[i]-'a'][chn[i]-'a'] = cost[i];
            }
            dist[org[i]-'a'][chn[i]-'a'] = min(dist[org[i]-'a'][chn[i]-'a'],cost[i]);
        }

        for(int k=0;k<26;k++){
            for(int i=0;i<26;i++){
                for(int j=0;j<26;j++){
                    if(dist[i][k] == -1 || dist[k][j] == -1){
                        continue;
                    }
                    if(dist[i][j] == -1){
                        dist[i][j] = dist[i][k] + dist[k][j];
                    }
                    else{
                        dist[i][j] = min(dist[i][j],dist[i][k] + dist[k][j]);
                    }

                }
            }
        }
        long long minCost = 0;
        for(int i=0;i<source.size();i++){
            if(source[i] != target[i]){
                if(dist[source[i] - 'a'][target[i] - 'a'] == -1)return -1;

                minCost = 0LL + minCost + dist[source[i] - 'a'][target[i] - 'a'];
            }
        }        
        return minCost;
    }
};
// 16TH JAN 2026
class Solution {
public:
int mod = 1e9+7;
    int maximizeSquareArea(int m, int n, vector<int>& hBars, vector<int>& vBars){
        hBars.push_back(1);
        hBars.push_back(m);
        vBars.push_back(1);
        vBars.push_back(n);
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());

        unordered_set<int>hDist;
        for(int i=0;i<hBars.size();i++){
            for(int j=i+1;j<hBars.size();j++){
                int dist = hBars[j] - hBars[i];
                hDist.insert(dist);
            }
        }

        int best = -1;
        for(int i=0;i<vBars.size();i++){
            for(int j=i+1;j<vBars.size();j++){
                int dist = vBars[j] - vBars[i];
                if(hDist.find(dist) != hDist.end()){
                    best = max(best,dist);
                }
            }
        }
        if(best == -1){
            return -1;
        }
        return (1LL*best%mod)*(1LL*best%mod) % mod;
    }
};
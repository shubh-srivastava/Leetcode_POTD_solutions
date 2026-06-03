// 3rd July 2026

class Solution {
public:
    int earliestFinishTime(vector<int>& LST, vector<int>& LD, vector<int>& WST, vector<int>& WD){
        int landmin = 1e9,watermin = 1e9;
        int n = LST.size(),m = WST.size();
        for(int i=0;i<n;i++){
            landmin = min(landmin,LST[i] + LD[i]);
        }
        for(int j=0;j<m;j++){
            watermin = min(watermin,WST[j] + WD[j]);
        }
        
        int mini = 1e9;
        for(int j=0;j<m;j++){
            mini = min(mini,max(0,WST[j] - landmin) + landmin + WD[j]);
        }

        for(int i=0;i<n;i++){
            mini = min(mini,max(0,LST[i] - watermin) + watermin + LD[i]);
        }
        return mini;
        
    }
};
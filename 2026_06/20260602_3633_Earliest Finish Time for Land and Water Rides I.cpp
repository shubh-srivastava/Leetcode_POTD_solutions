// 2nd July 2026

class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration){
        int n = landStartTime.size();
        int m = waterStartTime.size();

        int mint = 1e9;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int landc = landStartTime[i] + landDuration[i];
                int waterc = waterStartTime[j] + waterDuration[j];

                int case1 = landc + max(0, waterStartTime[j] - landc) + waterDuration[j];
                int case2 = waterc + max(0,landStartTime[i] - waterc) + landDuration[i];

                mint = min({mint,case1,case2});
            }
        }
        return mint;                
    }
};
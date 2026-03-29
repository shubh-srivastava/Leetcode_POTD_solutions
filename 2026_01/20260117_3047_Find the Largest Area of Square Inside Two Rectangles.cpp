class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bL, vector<vector<int>>& tR){
        long long maxarea = 0;
        int n = bL.size();
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                long long left = max(bL[i][0],bL[j][0]);
                long long bottom = max(bL[i][1],bL[j][1]);
                long long right = min(tR[i][0],tR[j][0]);
                long long top = min(tR[i][1],tR[j][1]);

                if(left < right && bottom < top){
                    long long side = min(top-bottom,right - left);
                    maxarea = max(maxarea,1LL*side*side);
                }  
            }
        }
        return maxarea;
    }
};
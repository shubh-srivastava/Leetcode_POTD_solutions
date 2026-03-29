// 15TH JAN 2026
class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars){
        sort(hBars.begin(),hBars.end());
        sort(vBars.begin(),vBars.end());
        int hx = hBars[0];
        int hy = hBars[0];
        int vx = vBars[0];
        int vy = vBars[0];

        int maxHspan = -1;
        int res = 1;
        int streak = 1;
        for(int i=1;i<hBars.size();i++){
            if(hBars[i] - hBars[i-1] == 1)streak++;
            else{
                streak = 1;
            }
            res = max(res,streak);
        }
        maxHspan = ++res;

        res = 1;
        streak = 1;
        int maxVspan = -1;
        for(int i=1;i<vBars.size();i++){
            if(vBars[i] - vBars[i-1] == 1)streak++;
            else{
                streak = 1;
            }
            res = max(res,streak);
        }
        maxVspan = ++res;

        int s = min(maxVspan,maxHspan);
        return s*s;
    }
};
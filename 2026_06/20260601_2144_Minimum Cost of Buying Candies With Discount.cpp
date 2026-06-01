// 1st July 2026

class Solution {
public:
    int minimumCost(vector<int>& cost){
        int n = cost.size();
        sort(cost.begin(),cost.end());
        int minc = 0;
        for(int i=n-1;i>=0;i-=3){
            minc += cost[i];
            if(i-1 >= 0){
                minc+=cost[i-1];
            }
        }
        return minc;
    }
};
// 21st June 2026

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins){
        sort(costs.begin(),costs.end());
        int i=0;
        int n = costs.size();
        for(int i=0;i<n;i++){
            coins -= costs[i];
            if(coins < 0){
                return i;
                break;
            }
        }       
        return n;
    }
};
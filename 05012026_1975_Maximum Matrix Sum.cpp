// 5th JAN 2026
class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix){
        long long sum = 0;
        int mine = INT_MAX;
        int neg = 0;

        for(auto r : matrix){
            for(int e : r){
                mine = min(mine,abs(e));

                if(e < 0){
                    sum -= e;
                    neg++;
                }
                else{
                    sum+=e;
                }
            }
        }
        return (neg&1)?sum-2*mine:sum;
        
    }
};
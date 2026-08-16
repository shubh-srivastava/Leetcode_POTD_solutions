// 16th August 2026
class Solution {
public:
    bool stoneGameIX(vector<int>& stones){
        int n = stones.size();
        int c0=0,c1=0,c2=0;
        for(int i : stones){
            if(i%3 == 0){
                c0++;
            }        
            else if(i%3 == 1){
                c1++;
            }    
            else{
                c2++;
            }
        }        

        if(c0%2 == 0){
            return (c1 > 0 && c2 > 0);
        }
        return bool(abs(c1 - c2) > 2);
    }
};

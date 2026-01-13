// 13th JAN 2026 
class Solution {
public:
double area;
    double totArea(vector<vector<int>>&squares){
        area = 0;
        for(auto it : squares){
            area += ((double)it[2])*((double)it[2]);
        }
        return area;
    }
    bool canHalf(vector<vector<int>>&squares,double y){
        double currArea = 0;
        for(auto &it : squares){
            double bottom = (double)it[1];
            double top = (double)it[1] + (double)it[2];
            if(y > bottom){
                double height = min(y, top) - bottom;
                currArea += it[2] * height;
            }
        }
        return currArea >= area / 2.0;
    }
    double separateSquares(vector<vector<int>>& squares){
        double lo = INT_MAX;
        double hi = INT_MIN;
        area = totArea(squares);
        for(auto it : squares){
            lo = min(lo,(double)it[1]);
            hi = max(hi,(double)it[1] + (double)it[2]);
        }        
        while(hi-lo > 1e-5){
            double mid = (hi + lo)/2;

            if(canHalf(squares,mid)){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        return lo;
    }
};
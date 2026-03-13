//13th march 2026

class Solution {
public:
    bool solve(long long tim, int h, vector<int>& wt){
        long long total = 0;

        for(long long t : wt){
            long long time_used = 0;
            long long k = 1;

            while(time_used + k * t <= tim){
                time_used += k * t;
                k++;
                total++;

                if(total >= h){
                    return true;
                }
            }
        }

        return false;
    }

    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes){

        long long lo = 1;
        long long hi = 1e16;
        long long ans = hi;

        while(lo <= hi){
            long long mid = lo + (hi - lo) / 2;

            if(solve(mid, mountainHeight, workerTimes)){
                ans = mid;
                hi = mid - 1;
            }
            else{
                lo = mid + 1;
            }
        }

        return ans;
    }
};
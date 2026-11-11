// 11th November 2026

class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth,int need1, int need2){
        vector<long long> xs ={0LL,(long long)need1,(long long)need2,(long long)max(need1, need2)};
        long long ans = LLONG_MAX;

        for(long long x : xs){
            long long cur =
                x * costBoth +
                max(0LL, (long long)need1 - x) * cost1 +
                max(0LL, (long long)need2 - x) * cost2;

            ans = min(ans, cur);
        }

        return ans;
    }
};
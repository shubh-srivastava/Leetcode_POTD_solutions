class Solution {
public:
    long long maximumHappinessSum(vector<int>& happ, int k){
        long long ans = 0;

        sort(happ.begin(),happ.end());
        long long n = happ.size();
        long long i=0;
        while(k > 0 && i < n){
            if(happ[n-1-i] > i){
                ans = 0LL + ans + happ[n-i-1]-i;
            }
            k--,i++;
        }        
        return ans;
    }
};
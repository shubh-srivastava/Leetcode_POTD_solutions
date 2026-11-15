// 15th November 2026

class Solution {
public:
    int numOfSubarrays(vector<int>& arr){
        int mod = 1e9 + 7;
        int n = arr.size();
        vector<int>prefix(n,0);
        prefix[0] = arr[0];
        for(int i=1;i<n;i++){
            prefix[i] = arr[i] + prefix[i-1];
        }
        int count = 0;
        int odd = 0;
        int even = 1;
        for(int i=0;i<n;i++){
            if(prefix[i]%2 == 0){
                even++;
                count = (odd + count)%mod;
            }
            else{
                odd++;
                count = (count + even)%mod;
            }
        }
        return count;
    }
};
// 5th November 2026

class Solution {
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d){
        sort(arr2.begin(),arr2.end());
        int ans = 0;
        int n = arr2.size();
        for(int num : arr1){
            int j = lower_bound(arr2.begin(),arr2.end(),num) - arr2.begin();
            if(j == 0){
                ans += (arr2[0] - num > d);
            }
            else if(j >= n){
                ans += (num - arr2[n-1] > d);
            }
            else{
                ans += (arr2[j] - num > d) && (num - arr2[j-1] > d);
            }
        }                
        return ans;
    }
};
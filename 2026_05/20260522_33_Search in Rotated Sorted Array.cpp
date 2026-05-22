// 22nd May 2026

class Solution {
public:
    int search(vector<int>& arr, int target) {
        int hi,lo;
        hi = arr.size()-1;
        lo = 0;
        while(lo<=hi){
            int mid = (hi+lo) /2;
            if(arr[mid] == target){
                return mid;
            }
            if(arr[lo] <= arr[mid]){
                if(arr[lo] <= target && target <= arr[mid]){
                    hi = mid-1;
                }
                else{
                    lo = mid+1;
                }
            }
            else{
                if(arr[mid] < target && target<= arr[hi]){
                    lo = mid+1;                    
                }
                else{
                    hi = mid-1;
                }
            }
        }
        return -1;
    }
};
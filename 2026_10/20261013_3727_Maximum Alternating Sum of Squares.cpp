// 13th October 2026

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums){
        priority_queue<int>pq;
        int n = nums.size();
        for(int i=0;i<n;i++){
            pq.push(abs(nums[i]));
        }
        long long ans = 0LL;
        int m = (n%2 == 0)? n/2 : (n/2+1);
        while(m--){
            ans = ans + pq.top()*pq.top();
            pq.pop();
        }

        while(!pq.empty()){
            ans = ans - pq.top()*pq.top();
            pq.pop();
        }
        return ans;
    }
};
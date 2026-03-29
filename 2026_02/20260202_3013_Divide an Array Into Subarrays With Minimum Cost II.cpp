//2nd FEB 2026

class Solution {
public:
typedef long long ll;
    long long minimumCost(vector<int>& nums, int k, int dist){
        int n = nums.size();
        set<pair<ll,ll>>kmin;
        set<pair<ll,ll>>rem;

        ll sum = 0;
        int i = 1;
        while(i - dist < 1){
            kmin.insert({nums[i],i});
            sum += nums[i];
            if(kmin.size() > k-1){
                pair<ll,ll>temp = *kmin.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                kmin.erase(temp);
            }
            i++;
        }

        ll res = LLONG_MAX;
        while(i<n){
            kmin.insert({nums[i],i});
            sum += nums[i];

            if(kmin.size() > k-1){
                pair<ll,ll>temp = *kmin.rbegin();
                sum -= temp.first;
                rem.insert(temp);
                kmin.erase(temp);
            }

            res = min(res,sum);

            pair<ll,ll> remove = {nums[i-dist],i-dist};
            if(kmin.find(remove) != kmin.end()){
                kmin.erase(remove);
                sum -= remove.first;

                if(!rem.empty()){
                    pair<ll,ll> temp = *rem.begin();
                    kmin.insert(temp);
                    sum += temp.first;
                    rem.erase(temp);
                }
            }
            else{
                rem.erase(remove);
            }
            i++;
        }
        return nums[0] + res;
    }
};
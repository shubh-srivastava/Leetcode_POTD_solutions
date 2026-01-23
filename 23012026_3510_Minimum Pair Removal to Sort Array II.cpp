class Solution {
public:
    int minimumPairRemoval(vector<int>& nums){
        int n = nums.size();

        vector<long long>temp(n);
        for(int i=0;i<n;i++){
            temp[i] = nums[i];
        }

        set<pair<long long,int>>minPair;

        vector<int>nextIdx(n,0);
        vector<int>prevIdx(n,0);
        for(int i=0;i<n;i++){
            nextIdx[i] = i+1;
            prevIdx[i] = i-1;
        }
        int badPairs = 0;

        for(int i=0;i<n-1;i++){
            if(temp[i] > temp[i+1]){
                badPairs++;
            }
            minPair.insert({temp[i] + temp[i+1],i});
        }

        int ops = 0;
        while(badPairs > 0){
            int first = minPair.begin()->second;
            int second = nextIdx[first];

            minPair.erase(begin(minPair));

            int first_left = prevIdx[first];
            int second_right = nextIdx[second];

            if(temp[first] > temp[second]){
                badPairs--;
            }

            if(first_left >= 0){
                if(temp[first_left] > temp[first] && temp[first_left] <= temp[first] + temp[second]){
                    badPairs--;
                }
                else if(temp[first_left] <= temp[first] && temp[first_left] > temp[first] + temp[second]){
                    badPairs++;
                }
            }
            if(second_right < n){
                if(temp[second_right] >= temp[second] && temp[second_right] < temp[first] + temp[second]){
                    badPairs++;
                }
                else if(temp[second_right] < temp[second] && temp[second_right] >= temp[first] + temp[second]){
                    badPairs--;
                }

            }
            
            if(first_left >=0){
                minPair.erase({temp[first_left] + temp[first],first_left});
                minPair.insert({temp[first_left] + temp[first] + temp[second],first_left});
            }
            if(second_right < n){
                minPair.erase({temp[second] + temp[second_right],second});
                minPair.insert({temp[first] + temp[second] + temp[second_right],first});
                prevIdx[second_right] = first;
            }
            nextIdx[first] = second_right;
            temp[first] += temp[second];

            ops++;

        }
        return ops;        
    }
};
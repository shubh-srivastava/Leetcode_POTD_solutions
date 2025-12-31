class Solution {
public:
    int mostBooked(int n, vector<vector<int>>& meetings){
        int m = meetings.size();
        sort(meetings.begin(),meetings.end());
        vector<long long>used(n,0);
        vector<long long>lastAvail(n,0);
        for(int j=0;j<m;j++){
            long long st = meetings[j][0];
            long long en = meetings[j][1];
            
            bool found = false;
            long long earlyTime = LLONG_MAX;
            int earlyRoom = 0;
            for(int i=0;i<n;i++){
                if(lastAvail[i] <= st){
                    lastAvail[i] = en;
                    used[i]++;
                    found = true;
                    break;
                }
                if(lastAvail[i] < earlyTime){
                    earlyTime = lastAvail[i];
                    earlyRoom = i;
                }
            }
            if(!found){
                lastAvail[earlyRoom] += (en-st);
                used[earlyRoom]++;
            }
        }
        int result = -1;
        long long maxi = LLONG_MIN;

        for(int i=0;i<n;i++){
            if(used[i] > maxi){
                maxi = used[i];
                result = i;
            }
        }

        return result;
    }
};
class Solution {
public:
    int bestClosingTime(string s){
        int j=0;
        int lastidx = -1;
        int curr = 0,maxp=0;
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == 'Y'){
                curr++;
            }
            else{
                curr--;
            }
            if(curr > maxp){
                maxp = curr;
                lastidx=i;
            }
        }
        return lastidx + 1;
    }
};
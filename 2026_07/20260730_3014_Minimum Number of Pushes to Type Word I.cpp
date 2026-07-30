// 30th July 2026

class Solution {
public:
    int minimumPushes(string word) {
        int n=word.size(),ans=0;
        for(int i=0;i<n;i++){
            if(i<=7){ans=ans+1;}
            else if(i<=15){ans+=2;}
            else if(i<=23){ans+=3;}
            else{ans+=4;}
        }
        return ans;
    }
};
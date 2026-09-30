// 30th September 2026

class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq){
        int n = seq.size();
        vector<int>ans(n,0);

        int d = 0;
        for(int i=0;i<n;i++){
            if(seq[i] == '('){
                d++;
                ans[i] = (d%2);
            }
            else{
                ans[i] = (d%2);
                d--;
            }
        }        
        return ans;
    }
};
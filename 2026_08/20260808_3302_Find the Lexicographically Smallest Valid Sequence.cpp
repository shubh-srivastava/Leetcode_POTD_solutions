// 8th August 2026

class Solution {
public:
    vector<int> validSequence(string word1, string word2){
        int n = word1.size();
        int m = word2.size();

        int R = m-1;
        int C = 0;
        vector<int> Right(n);
        for(int i=n-1;i>=0;i--){
            Right[i] = C;
            if(R >=0 && word1[i] == word2[R]){
                R--;
                C++;
            }
        } 
        
        vector<int>ans;
        bool changed = false;
        int j=0;

        for(int i=0;i<n && j<m;i++){
            if(word1[i] == word2[j]){
                ans.push_back(i);
                j++;
            }
            else if(!changed && Right[i] >= m-1-j){
                ans.push_back(i);
                j++;
                changed = true;
            }
        }
        if(j == m){
            return ans;
        }
        return {};
    }
};
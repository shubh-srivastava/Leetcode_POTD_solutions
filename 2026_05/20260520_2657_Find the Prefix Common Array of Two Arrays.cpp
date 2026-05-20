// 20th May 2026

class Solution {
public:
    int count(vector<int>&hash){
        int num = 0;
        for(int i=0;i<hash.size();i++){
            if(hash[i] == 2){
                num++;
            }
        }
        return num;
    }
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B){
        int n = A.size();
        vector<int>hash(n,0);
        vector<int>ans(n,0);
        for(int i=0;i<n;i++){
            hash[A[i]-1]++;
            hash[B[i]-1]++;
            ans[i] = count(hash);
        }      
        return ans;         
    }
};
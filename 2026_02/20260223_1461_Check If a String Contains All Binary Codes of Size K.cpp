// 23rd feb 2026

class Solution {
public:
    bool hasAllCodes(string s, int k){
        int n = s.size();
        if(n < k)return false;
        unordered_set<string>st;
        for(int i=0;i<=n-k;i++){
            string temp = s.substr(i,k);
            if(st.find(temp) == st.end()){
                st.insert(temp);
            }
            if(st.size() >= pow(2,k)){
                return true;
            }
        }  
        if(st.size() >= pow(2,k)){
                return true;
        }
        return false;      
    }
};
// 29th March 2026

class Solution {
public:
    bool canBeEqual(string s1, string s2){
        unordered_map<char,int>even;
        unordered_map<char,int>odd;
        int n = s1.size();
        for(int i=0;i<n;i++){
            if(i%2){
                odd[s1[i]]++;
            }
            else{
                even[s1[i]]++;
            }
        }

        for(int i=0;i<n;i++){
            if(i%2){
                if(odd.find(s2[i]) == odd.end()){
                    return false;
                }
                else{
                    odd[s2[i]]--;
                    if(odd[s2[i]] == 0){
                        odd.erase(s2[i]);
                    }
                }
            }
            else{
                if(even.find(s2[i]) == even.end()){
                    return false;
                }
                else{
                    even[s2[i]]--;
                    if(even[s2[i]] == 0){
                        even.erase(s2[i]);
                    }
                }
            }
        }
        return true;
    }
};
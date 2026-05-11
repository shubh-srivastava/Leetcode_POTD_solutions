// 11th May 2026

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums){
        vector<int>res;
        for(int i:nums){
            string s = to_string(i);
            for(char ch : s){
                res.push_back(ch - '0');
            }
        }
        return res;        
    }
};
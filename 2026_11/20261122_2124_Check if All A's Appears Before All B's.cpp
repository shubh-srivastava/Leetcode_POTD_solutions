// 22nd November 2026

class Solution {
public:
    bool checkString(string s){
        int f = s.find("ba");
        if(f != string::npos){
            return false;
        }       
        return true;
    }
};
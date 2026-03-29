// 20th eb 2026

class Solution {
public:
    string makeLargestSpecial(string s){
        vector<string>special;

        int st = 0;
        int sum = 0;
        for(int i=0;i<s.size();i++){
            sum += s[i] == '1' ? 1 : -1;

            if(sum == 0){
                string inner = s.substr(st + 1,i-st-1);
                special.push_back("1" + makeLargestSpecial(inner) + "0");
                st = i+1;
            }
        }
        sort(special.begin(),special.end(),greater<string>());
        string result;
        for(string &str : special){
            result += str;
        }
        return result;
        
    }
};
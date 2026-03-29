//17th feb 2026

class Solution {
public:

    vector<string> readBinaryWatch(int turnedOn){
        vector<string>ans;
        for(int hr = 0;hr<=11;hr++){
            for(int min=0;min<=59;min++){
                if(__builtin_popcount(hr) + __builtin_popcount(min) == turnedOn){
                    string hour = to_string(hr);
                    string minute = (min < 10 ? "0" : "") + to_string(min);
                    ans.push_back(hour + ":" + minute);
                }
            }
        }
        return ans;                
    }
};
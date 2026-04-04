// 4th April 2026

class Solution {
public:
    string decodeCiphertext(string encodedText, int rows){
        int len = encodedText.size();
        int cols = len/rows;
        string org = "";
        for(int c = 0;c < cols;c++){
            for(int j=c;j<len;j+=(cols+1)){
                org += encodedText[j];
            }
        }       
        while(!org.empty() && org.back() == ' '){
            org.pop_back();
        }
        return org;
    }
};
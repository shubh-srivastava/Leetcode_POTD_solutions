//31st JAN 2026

class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target){
        char ret = 'z';
        bool found = false;
        int n = letters.size();
        for(int i=n-1;i>=0;i--){
            if(letters[i] > target){
                ret = letters[i];
                found = true;
            }
        }
        if(!found)return letters[0];
        return ret;

    }
};
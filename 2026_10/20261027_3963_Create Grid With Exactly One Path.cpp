// 27th October 2026

class Solution {
public:
    vector<string> createGrid(int m, int n){
        vector<string> ans;

        for(int i=0;i<m-1;i++){
            string temp = ".";
            temp += string(n - 1, '#');
            ans.push_back(temp);
        }

        ans.push_back(string(n, '.'));

        return ans;
    }
};
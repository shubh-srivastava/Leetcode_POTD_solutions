// 26th September 2026

class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge){
        string curr = "";
        unordered_map<string,string>know;
        int n = knowledge.size();
        for(int i=0;i<n;i++){
            know[knowledge[i][0]] = knowledge[i][1]; 
        }
        string ans = "";
        n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '('){
                i++;
                while(s[i] != ')'){
                    curr += s[i];
                    i++;
                }
                if(know.find(curr) != know.end()){
                    ans += know[curr];
                }
                else{
                    ans += "?";
                }
                curr = "";
            }
            else{
                ans += s[i];
            }            
        }    
        return ans;  
    }
};
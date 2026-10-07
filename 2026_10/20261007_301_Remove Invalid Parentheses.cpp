// 7th October 2026

class Solution {
public:
int n;
unordered_set<string>st;
int maxlen;

    void solve(string &s,int i,string & curr,int count){
        if(count < 0){
            return;
        }
        if(i == n){
            if(count == 0){
                if(curr.size() > maxlen){
                    maxlen = curr.size();
                    st.clear();
                }
                if(curr.size() == maxlen){
                    st.insert(curr);
                }
            }
            return;
        }

        if(s[i] != '(' && s[i] != ')'){
            curr.push_back(s[i]);
            solve(s,i+1,curr,count);
            curr.pop_back();
            return;
        }
        
        curr.push_back(s[i]);
        solve(s,i+1,curr,count + (s[i] == '('? 1 : -1));
        curr.pop_back();

        solve(s,i+1,curr,count);
    }
    vector<string> removeInvalidParentheses(string s){
        n = s.size();
        maxlen = 0;
        string curr = "";

        solve(s,0,curr,0); 
        return vector<string>(st.begin(),st.end());      
    }
};
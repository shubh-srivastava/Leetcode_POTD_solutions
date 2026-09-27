// 27th September 2026

class Solution {
public:
    string reverseParentheses(string s){
        stack<int> st;
        for(int i = 0;i<s.size();i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                int l = st.top();
                st.pop();
                reverse(s.begin() + l + 1, s.begin() + i);
            }
        }

        string ans;
        for(char c : s){
            if(c != '(' && c != ')'){
                ans += c;
            }
        }
        return ans;     
    }
};
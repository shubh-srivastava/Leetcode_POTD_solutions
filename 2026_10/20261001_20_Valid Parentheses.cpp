// 1st October 2026

class Solution {
public:
    bool isValid(string s){
        stack<char> st;
        //st.clear();
        int n = s.size();

        for(int i=0;i<n;i++){
            if(!st.empty()){
                if(st.top() == '(' && s[i] == ')'){
                    st.pop();
                }
                else if(st.top() == '{' && s[i] == '}'){
                    st.pop();
                }
                else if(st.top() == '[' && s[i] == ']'){
                    st.pop();
                }
                else{
                    st.push(s[i]);
                }
            }
            else{
                st.push(s[i]);
            }
        }        

        // while(!st.empty()){
        //     cout<<st.top()<<" ";
        //     st.pop();
        // }

        if(!st.empty()) return false;

        return true;
    }
};
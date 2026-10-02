// 2nd October 2026

class Solution {
public:
    void parenthesis(vector<string>& v,string s,int n,int count,int number){
        if(count==0 && number==2*n){
            v.push_back(s);
            return;
        }
        if(count<0 || count>n || (number==2*n && count!=0)){
            return;
        }
        parenthesis(v,s+"(", n, count+1, number+1);
        parenthesis(v,s+")", n, count-1, number+1);

    }
    vector<string> generateParenthesis(int n) {
        vector<string>v;
        parenthesis(v,"",n,0,0);
        return v;
    }
};
// 14th march 2026

class Solution {
public:
vector<string> happy;
int n;
    void solve(int i,string temp){
        if(i == n){
            happy.push_back(temp);
            return;
        }
        for(char c : {'a','b','c'}){
            if(temp.empty() || temp.back() != c){
                solve(i+1, temp + c);
            }
        }
    }
    string getHappyString(int N, int k){
        n = N;
        string temp = "";
        solve(0,temp);
        sort(happy.begin(),happy.end());

        if(k > happy.size()){
            return "";
        }
        return happy[k-1];
    }
};


// better solution 
class Solution {
public:
string ans = "";
int count = 0;

    void dfs(int n,int k,string temp){
        if(ans != ""){
            return;
        }
        if(temp.size() == n){
            count++;
            if(count == k){
                ans = temp;
            }
            return;
        }

        for(char c : {'a','b','c'}){
            if(temp.empty() || temp.back() != c){
                dfs(n,k,temp+c);
            }
        }
    }
    string getHappyString(int n, int k) {
        dfs(n,k,"");
        return ans;
    }
};
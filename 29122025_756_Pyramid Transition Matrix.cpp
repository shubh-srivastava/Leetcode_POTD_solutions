class Solution {
public:
    unordered_map<string,vector<char>>mp;
    unordered_map<string,bool>memo;

    bool dfs(string& bottom){
        if(bottom.size() == 1){
            return true;
        }
        if(memo.count(bottom)){
            return memo[bottom];
        }
        string next = "";
        return memo[bottom] = buildNext(0,next,bottom);
    }

    bool buildNext(int idx,string& next,string& bottom){
        if(idx == bottom.size()-1){
            return dfs(next);
        }

        string key = bottom.substr(idx, 2);
        if(mp.find(key) == mp.end()){
            return false;
        }
        for(char c: mp[key]){
            next.push_back(c);
            if(buildNext(idx+1,next,bottom)){
                return true;
            }
            next.pop_back();
        }
        return false;
    }
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        for(string &s : allowed){
            mp[s.substr(0,2)].push_back(s[2]);
        }
        return dfs(bottom);
    }
};
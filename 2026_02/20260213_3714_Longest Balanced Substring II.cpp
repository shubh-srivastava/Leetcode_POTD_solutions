// 13th feb 2026

class Solution {
public:
    struct hash_pair {
        size_t operator()(const pair<int,int>& p) const {
            return hash<long long>()(
                ((long long)p.first << 32) ^ p.second
            );
        }
    };
    int longestBalanced(string s){
        int n = s.size();
        int ans = 0;
        int cur = 1;
        for(int i = 1; i < n; i++){
            if(s[i] == s[i-1]) cur++;
            else {
                ans = max(ans, cur);
                cur = 1;
            }
        }
        ans = max(ans, cur);
        for(int x = 0; x < 3; x++){
            for(int y = x+1; y < 3; y++){
                char ch1 = 'a' + x;
                char ch2 = 'a' + y;

                unordered_map<int,int> mp;
                mp[0] = -1;

                int c1 = 0, c2 = 0;
                for(int i=0;i<n;i++){
                    if(s[i] != ch1 && s[i] != ch2){
                        mp.clear();
                        mp[0] = i;
                        c1 = c2 = 0;
                        continue;
                    }
                    if(s[i] == ch1){ 
                        c1++;
                    }
                    else{
                        c2++;
                    }
                    int diff = c1 - c2;

                    if(mp.count(diff)){
                        ans = max(ans, i - mp[diff]);
                    }
                    else{
                        mp[diff] = i;
                    }
                }
            }
        }
        int ca = 0, cb = 0, cc = 0;
        unordered_map<pair<int,int>,int,hash_pair> mp3;
        mp3[{0,0}] = -1;

        for(int i = 0; i < n; i++){
            if(s[i]=='a') ca++;
            else if(s[i]=='b') cb++;
            else cc++;

            pair<int,int> key = {ca-cb, ca-cc};

            if(mp3.count(key))
                ans = max(ans, i - mp3[key]);
            else
                mp3[key] = i;
        }

        return ans;
    }
};

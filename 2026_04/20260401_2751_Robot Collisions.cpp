// 1st April 2026

class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions){
        int n = positions.size();
        map<int,int>mp;
        for(int i=0;i<n;i++){
            mp[positions[i]] = i;
        }
        
        stack<int>st;
        for(auto &it : mp){
            int idx = it.second;
            if(directions[idx] == 'R'){
                st.push(idx);
            }
            else{
                while(!st.empty() && healths[idx] > 0){
                    int topidx = st.top();
                    if(healths[topidx] < healths[idx]){
                        healths[topidx] = 0;
                        st.pop();
                        healths[idx]--;
                    }
                    else if(healths[topidx] == healths[idx]){
                        st.pop();
                        healths[idx] = healths[topidx] = 0;
                        break;
                    }
                    else{
                        healths[topidx]--;
                        healths[idx] = 0;
                        break;
                    }
                }
            }
        }
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(healths[i] > 0){
                ans.push_back(healths[i]);
            }
        }
        return ans;
        
    }
};
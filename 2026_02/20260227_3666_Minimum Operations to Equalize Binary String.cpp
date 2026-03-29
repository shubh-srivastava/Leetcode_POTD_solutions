// 27th feb 2026

class Solution {
public:
    int minOperations(string s, int k){
        int n = s.size();

        int stzero = 0;
        for(char &ch : s){
            if(ch == '0'){
                stzero++;
            }
        }

        if(stzero == 0){
            return 0;
        }

        vector<int> ops(n+1,-1);
        set<int> evenSet;
        set<int> oddSet;

        for(int count = 0; count <= n; count++) {
            if(count%2 == 0) {
                evenSet.insert(count);
            } else {
                oddSet.insert(count);
            }
        }
        queue<int>q;
        q.push(stzero);
        ops[stzero] = 0;
        if(stzero%2 == 0){
            evenSet.erase(stzero);
        }
        else{
            oddSet.erase(stzero);
        }

        while(!q.empty()){
            int z = q.front();
            q.pop();
            int minnz = z + k - 2 * min(k,z);
            int maxnz = z + k - 2 * max(0,k-n+z);
            set<int> & currSet = (minnz%2 == 0)?evenSet:oddSet;
            auto it = currSet.lower_bound(minnz);
            while(it != currSet.end() && *it <= maxnz){
                int newz = *it;

                if(ops[newz] == -1){
                    ops[newz] = ops[z] + 1;

                    if(newz == 0){
                        return ops[newz];
                    }

                    q.push(newz);
                }
                it = currSet.erase(it);
            }
        }
        return -1;        
    }
};
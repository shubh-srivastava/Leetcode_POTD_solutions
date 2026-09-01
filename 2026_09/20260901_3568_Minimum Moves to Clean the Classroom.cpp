// 1st September 2026

class Solution {
public:
struct State{
    int x;
    int y;
    int mask;
    int e;
    int steps;
};
    int minMoves(vector<string>& classroom, int energy){
        int n = classroom.size();
        int m = classroom[0].size();
        int sx,sy;
        vector<vector<int>>litterID(n,vector<int>(m,-1));
        int k = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(classroom[i][j] == 'S'){
                    sx = i;
                    sy = j;
                }
                else if(classroom[i][j] == 'L'){
                    litterID[i][j] = k++;
                }
            }
        }
        int fullMask = (1<<k) - 1;

        vector<vector<vector<int>>>bestEnergy(n,vector<vector<int>>(m,vector<int>(1<<k,-1)));

        queue<State>q;
        q.push({sx,sy,0,energy,0});
        bestEnergy[sx][sy][0] = energy;
        int delr[] = {1,0,-1,0};
        int delc[] = {0,1,0,-1};

        while(!q.empty()){
            auto cur = q.front();
            q.pop();

            if(cur.mask == fullMask){
                return cur.steps;
            }

            for(int i=0;i<4;i++){
                int nr = cur.x + delr[i];
                int nc = cur.y + delc[i];
                if(nr<0 || nc<0 || nr>=n || nc>= m)continue;
                if(classroom[nr][nc] == 'X')continue;

                int ne = cur.e-1;
                if(ne < 0)continue;

                int mask = cur.mask;

                if(classroom[nr][nc] == 'L'){
                    mask |= (1<<litterID[nr][nc]);
                }
                if(classroom[nr][nc] == 'R'){
                    ne = energy;
                }
                if(ne <= bestEnergy[nr][nc][mask])continue;
                
                bestEnergy[nr][nc][mask] = ne;
                q.push({nr,nc,mask,ne,cur.steps+1});

            }              
        }
        return -1;
        
    }
};
// 23rd March 2026

class Solution {
public:
int M = 1e9 + 7;
    int maxProductPath(vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        const int MOD = 1e9+7;

        vector<vector<__int128>> mx(n, vector<__int128>(m));
        vector<vector<__int128>> mn(n, vector<__int128>(m));

        mx[0][0] = mn[0][0] = grid[0][0];

        for(int j=1;j<m;j++){
            mx[0][j] = mn[0][j] = mx[0][j-1] * grid[0][j];
        }

        for(int i=1;i<n;i++){
            mx[i][0] = mn[i][0] = mx[i-1][0] * grid[i][0];
        }

        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                __int128 a = mx[i-1][j] * grid[i][j];
                __int128 b = mn[i-1][j] * grid[i][j];
                __int128 c = mx[i][j-1] * grid[i][j];
                __int128 d = mn[i][j-1] * grid[i][j];

                mx[i][j] = max({a,b,c,d});
                mn[i][j] = min({a,b,c,d});
            }
        }

        if(mx[n-1][m-1] < 0) return -1;

        return (long long)(mx[n-1][m-1] % MOD);

    }
};
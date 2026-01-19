// 19 JAN 2026
// 1st solution preforms better 
class Solution {
public:
int n,m;
    int findSum(int i,int j,int r2,int c2,vector<vector<int>>&prefix){
        int sum = prefix[r2][c2];

        if(i > 0){
            sum -= prefix[i-1][c2];
        }
        if(j > 0){
            sum -= prefix[r2][j-1];
        }
        if(i > 0 && j > 0){
            sum += prefix[i-1][j-1];
        } 
        return sum;

    }
    int maxSideLength(vector<vector<int>>& mat, int threshold){
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>>prefix(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = 
                (i>0?prefix[i-1][j]:0) 
                +(j>0?prefix[i][j-1]:0) 
                -((i>0 && j>0) ? prefix[i-1][j-1]:0)
                +mat[i][j];
            }
        }
        int best = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int off=best;off<min(n-i,m-j);off++){
                    int r = i + off;
                    int c = j + off;
                    
                    int sum = findSum(i,j,r,c,prefix);

                    if(sum <= threshold){
                        best = max(best,off+1);
                        // cout<<i<<" "<<j<<" "<<sum<<" "<<best<<endl;
                    }
                    else{
                        break;
                    }

                }
            }
        }

        return best;        
        
    }
};


// 2nd solution better approach
class Solution {
public:
int n,m;
    int findSum(int i,int j,int r2,int c2,vector<vector<int>>&prefix){
        int sum = prefix[r2][c2];

        if(i > 0){
            sum -= prefix[i-1][c2];
        }
        if(j > 0){
            sum -= prefix[r2][j-1];
        }
        if(i > 0 && j > 0){
            sum += prefix[i-1][j-1];
        } 
        return sum;

    }

    bool check(int side,vector<vector<int>>&prefix,int threshold){
        for(int i=0;i + side -1<n;i++){
            for(int j=0;j + side -1<m;j++){
                int r = i + side - 1;
                int c = j + side - 1;
                if(findSum(i,j,r,c,prefix) <= threshold){
                    return true;
                }
            }
        }
        return false;
    }
    int maxSideLength(vector<vector<int>>& mat, int threshold){
        n = mat.size();
        m = mat[0].size();

        vector<vector<int>>prefix(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                prefix[i][j] = 
                (i>0?prefix[i-1][j]:0) 
                +(j>0?prefix[i][j-1]:0) 
                -((i>0 && j>0) ? prefix[i-1][j-1]:0)
                +mat[i][j];
            }
        }
        int lo = 1;
        int hi = min(n,m);

        int res = 0;

        while(hi >= lo){
            int mid = (hi+lo)/2;
            if(check(mid,prefix,threshold)){
                res = mid;
                lo = mid+1;
            }
            else{
                hi = mid-1;
            }
        }

        return res;        
        
    }
};
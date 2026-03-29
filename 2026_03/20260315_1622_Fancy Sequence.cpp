// 15th March 2026

class Fancy {
public:
const long long MOD = 1e9+7;
long long mul = 1;
long long add = 0;
vector<long long>arr;

    long long modInv(long long x){
        long long res = 1,p = MOD -2;
        while(p){
            if(p&1){
                res = (res*x)%MOD;
            }
            x = (x*x)%MOD;
            p >>= 1;
        }
        return res;
    }
    Fancy() {
        
    }
    
    void append(int val){
        long long v = (val - add + MOD)%MOD;
        v = (v * modInv(mul))%MOD;
        arr.push_back(v);        
    }
    
    void addAll(int inc) {
        add = (add + inc)%MOD;
    }
    
    void multAll(int m) {
        mul = (mul * m)%MOD;
        add = (add * m)%MOD;
    }
    
    int getIndex(int idx) {
        if(idx >= arr.size()){
            return -1;
        }        
        return (arr[idx]*mul + add)%MOD;
    }
};

/**
 * Your Fancy object will be instantiated and called as such:
 * Fancy* obj = new Fancy();
 * obj->append(val);
 * obj->addAll(inc);
 * obj->multAll(m);
 * int param_4 = obj->getIndex(idx);
 */
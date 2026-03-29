// 3rd march 

class Solution {
public:
    string invert(string s){
        int n = s.size();
        for(int i=0;i<n;i++){
            if(s[i] == '0'){
                s[i] = '1';
            }
            else{
                s[i] = '0';
            }
        }
        return s;
    }
    char findKthBit(int n, int k){
        string s = "";
        string prev = "0";
        while(n > 1){
            string prevrev = invert(prev);
            reverse(prevrev.begin(),prevrev.end());
            s = prev + '1' + prevrev;
            prev = s;
            n--;
        } 
        // cout<<s<<endl;
        return prev[k-1];

    }
};
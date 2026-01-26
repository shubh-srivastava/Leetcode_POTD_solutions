class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& cap){
        int sum = accumulate(apple.begin(),apple.end(),0);

        sort(cap.begin(),cap.end());
        int n = cap.size();
        int box = 0;
        for(int i=n-1;i>=0;i--){
            if(sum > 0){
                box++;
                sum = sum-cap[i];
            }
            else{
                break;
            }
        }
        return box;
    }
};
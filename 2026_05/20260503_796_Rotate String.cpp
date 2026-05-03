// 3rd May 2026

class Solution {
public:
    bool rotateString(string& s, string& goal) {
        return s.size()==goal.size() && (s+s).find(goal)!=-1;
    }
};
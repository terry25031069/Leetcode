// https://leetcode.com/problems/rotate-string

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()) return false;
        for(int i = 0; i < s.size(); i++){
            if(s == goal) return true;
            s = s.substr(1) + s.front();
        }
        return false;
    }
};
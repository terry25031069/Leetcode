// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        string tmp = "";
        for(int i = 0; i < s.size(); i++){
            if(tmp.size()){
                int a = s[i] - tmp.back();
                if(a > 0 && a < 3) tmp.pop_back();
                else tmp += s[i];
            }else tmp += s[i];
        }
        return (tmp.size() == 0);
    }
};
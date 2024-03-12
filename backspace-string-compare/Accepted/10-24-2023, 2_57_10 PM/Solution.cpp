// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    string process(string s){
        string ans = "";
        for(auto i: s){
            if(i == '#') {if(ans.size())ans.pop_back();}
            else ans += i;
        }
        return ans;
    }
    bool backspaceCompare(string s, string t) {
        return process(s) == process(t);
    }
};
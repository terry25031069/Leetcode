// https://leetcode.com/problems/backspace-string-compare

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        string a, b;
        for(auto i: s){
            a.push_back(i);
            if(i == '#'){
                if(a.size())a.pop_back();
                if(a.size())a.pop_back();
            }
        }
        for(auto i: t){
            b.push_back(i);
            if(i == ''#'){
                if(b.size())b.pop_back();
                if(b.size())b.pop_back();
            }
        }
        return a == b;
    }
};
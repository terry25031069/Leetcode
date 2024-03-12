// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        string tmp = "";
        for(int i = 0; i < s.size(); i++){
            if(tmp.size() > 1 && ((tmp.back() == '}' && s[i] == '{') ||
                                (tmp.back() == ']' && s[i] == '[') ||
                                (tmp.back() == ')' && s[i] == '('))){
                tmp.pop_back();
            }else tmp += s[i];
        }
        cout << tmp << endl;
        return (tmp.size() == 0);
    }
};
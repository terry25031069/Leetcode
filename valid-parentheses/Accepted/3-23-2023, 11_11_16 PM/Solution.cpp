// https://leetcode.com/problems/valid-parentheses

class Solution {
public:
    bool isValid(string s) {
        string tmp = "";
        for(int i = 0; i < s.size(); i++){
            tmp += s[i];
            if(tmp.size() > 1 && ((tmp[tmp.size() - 1] == '}' && tmp[tmp.size() - 2] == '{') ||
                                (tmp[tmp.size() - 1] == ']' && tmp[tmp.size() - 2] == '[') ||
                                (tmp[tmp.size() - 1] == ')' && tmp[tmp.size() - 2] == '('))){
                tmp.pop_back();
                tmp.pop_back();
            }
        }
        //cout << tmp << endl;
        return (tmp.size() == 0);
    }
};
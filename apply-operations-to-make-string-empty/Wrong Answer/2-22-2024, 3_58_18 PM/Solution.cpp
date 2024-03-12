// https://leetcode.com/problems/apply-operations-to-make-string-empty

class Solution {
public:
    string op(string s){
        char letter[26] = {};
        string ans = "";
        for(char c: s){
            letter[c-'a']++;
            if(letter[c-'a'] > 1) ans += c;
        }
        return ans;
    }
    string lastNonEmptyString(string s) {
        string ansStr;
        while(s != ""){
            ansStr = s;
            s = op(s);
        }
        return ansStr;
    }
};
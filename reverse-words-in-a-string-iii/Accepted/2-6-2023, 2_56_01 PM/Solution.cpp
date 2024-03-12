// https://leetcode.com/problems/reverse-words-in-a-string-iii

class Solution {
public:
    string reverseWords(string s) {
        stringstream ss; ss.str(s);
        string ans = "";
        while(ss >> s){
            reverse(s.begin(), s.end());
            ans += s + ' ';
        }
        return ans.substr(0, ans.size() - 1);
    }
};
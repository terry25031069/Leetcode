// https://leetcode.com/problems/longest-palindromic-substring

class Solution {
public:
    string longest(string &s, int l, int r){
        while(l > 0 && r < s.size() - 1 && s[l - 1] == s[r + 1]){
            l--, r++;
        }
        string tmp = s.substr(l, r - l + 1);
        return tmp;
    }
    string longestPalindrome(string s) {
        string ans;
        if(s.size() == 1) return s;
        for(int i = 0; i < s.size(); i++){
            string tmp0 = longest(s, i, i);
            if(tmp0.size() > ans.size()) ans = tmp0;
            if(i < s.size() - 1 && s[i] == s[i+1]){
                string tmp1 = longest(s, i, i+1); 
                if(tmp1.size() > ans.size()) ans = tmp1;
            }
        }
        return ans;
    }
};
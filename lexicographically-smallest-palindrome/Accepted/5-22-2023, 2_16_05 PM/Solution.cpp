// https://leetcode.com/problems/lexicographically-smallest-palindrome

class Solution {
public:
    string makeSmallestPalindrome(string s) {
        string ans = "";
        for(int i = 0; i < s.size(); i++){
            ans += min(s[i], s[s.size() - 1 - i]);
        }
        return ans;
    }
};
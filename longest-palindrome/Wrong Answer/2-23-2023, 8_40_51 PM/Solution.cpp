// https://leetcode.com/problems/longest-palindrome

class Solution {
public:
    int longestPalindrome(string s) {
        map<char, int> m;
        for(auto c: s) m[c]++;
        int ans = 0, ma = 0;
        for(auto [k, v]: m){
            if(v == 1) ma = v;
            else ans += v - (v & 1);
        }
        ans += ma;
        return ans;
    }
};
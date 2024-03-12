// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        int c[26] = {};
        for(auto ch: s) c[ch-'a']++;
        for(auto ch: t) c[ch-'a']--;
        int ans = 0;
        for(int i = 0; i < 26; i++) ans += abs(c[i]);
        return ans / 2;
    }
};
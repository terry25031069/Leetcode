// https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram

class Solution {
public:
    int minSteps(string s, string t) {
        int a[26] = {}, ans = 0;
        for(char ch: s) a[ch - 'a']++;
        for(char ch: t) a[ch - 'a']--;
        for(int i = 0; i < 26; i++) ans += abs(a[i]);
        return ans / 2;
    }
};
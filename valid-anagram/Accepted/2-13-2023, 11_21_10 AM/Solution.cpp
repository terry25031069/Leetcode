// https://leetcode.com/problems/valid-anagram

class Solution {
public:
    bool isAnagram(string s, string t) {
        int cnt[26] = {};
        for(auto c: s) cnt[c - 'a']++;
        for(auto c: t) cnt[c - 'a']--;
        for(auto o: cnt) if(o) return false;
        return true;
    }
};
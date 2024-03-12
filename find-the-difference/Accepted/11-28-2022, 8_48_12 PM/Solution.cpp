// https://leetcode.com/problems/find-the-difference

class Solution {
public:
    char findTheDifference(string s, string t) {
        int a0[26] = {};
        for(auto i: s) a0[i - 'a']++;
        for(auto i: t) a0[i - 'a']--;
        for(int i = 0; i < 26; i++)if(a0[i] == -1) return i+'a';
        return 0;
    }
};
// https://leetcode.com/problems/first-letter-to-appear-twice

class Solution {
public:
    char repeatedCharacter(string s) {
        int c[26] = {};
        for(auto ch: s){
            c[ch-'a']++;
            if(c[ch-'a'] == 2) return ch;
        } 
        return 'a';
    }
};
// https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int c[26]  {};
        for(auto s: words){
            for(auto ch: s) c[ch - 'a']++;
        }
        for(int i = 0; i < 26; i++){
            if(c[i] % words.size()) return false;
        }
        return true;
    }
};
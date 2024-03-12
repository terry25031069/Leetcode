// https://leetcode.com/problems/ransom-note

class Solution {
public:
    int letter[26] = {};
    bool canConstruct(string ransomNote, string magazine) {
        for(auto i: ransomNote) letter[i - 'a']--;
        for(auto i: magazine) letter[i - 'a']++;
        for(int i = 0; i < 26; i++){
            if(letter[i] < 0){
                return false;
            }
        }
        return true;
    }
};
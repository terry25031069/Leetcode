// https://leetcode.com/problems/detect-capital

class Solution {
public:
    bool detectCapitalUse(string word) {
        if(word.size() == 1) return true;
        if(isupper(word[0])){
            if(word.size() == 2) return true;
            for(int i = 1; i < word.size() - 1; i++){
                if(islower(word[i]) != islower(word[i + 1])) return false;
            }
        }
        for(int i = 0; i < word.size() - 1; i++){
            if(islower(word[i]) != islower(word[i + 1])) return false;
        }
        return true;
    }
};
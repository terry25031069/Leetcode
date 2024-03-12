// https://leetcode.com/problems/count-vowel-strings-in-ranges

class Solution {
public:
    bool isvowel(char c){
        if(c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        vector<int>word{0};
        for(auto s: words){
            if(isvowel(s[0]) && isvowel(s.back())){
                word.push_back(1);
            }else word.push_back(0);
        }
        for(int i = 1; i < word.size(); i++){
            word[i] += word[i - 1];
        }
        vector<int> ans;
        for(auto v: queries){
            int l = v[0] + 1, r = v[1] + 1;
            ans.push_back(word[r] - word[l - 1]);
        }
        return ans;
    }
};
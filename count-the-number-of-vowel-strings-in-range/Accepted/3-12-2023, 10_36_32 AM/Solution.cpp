// https://leetcode.com/problems/count-the-number-of-vowel-strings-in-range

class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        string vow = "aeiou";
        int ans = 0;
        for(int i = left; i <= right; i++){
            if(vow.find(words[i][0]) != string::npos && vow.find(words[i].back()) != string::npos) ans++;
        }
        return ans;
    }
};
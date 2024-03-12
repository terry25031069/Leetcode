// https://leetcode.com/problems/reverse-vowels-of-a-string

class Solution {
public:
    string reverseVowels(string s) {
        vector<char>vowels;
        int a[1000] = {};
        a['a'] = a['e'] = a['i'] = a['o'] = a['u'] = 1;
        for(int i = 0; i < s.size(); i++){
            if(a[tolower(s[i])] == 1)vowels.push_back(s[i]);
        }
        reverse(vowels.begin(), vowels.end());
        int location = 0;
        for(int i = 0; i < s.size(); i++){
            if(a[tolower(s[i])] == 1)s[i] = vowels[location++];
        }
        return s;
    }
};
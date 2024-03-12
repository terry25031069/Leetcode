// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        int visit[26] = {}, loc[26] = {};
        for(int i = 0; i < s.size(); i++){
            visit[s[i] - 'a']++;
            if(!loc[s[i] - 'a']) loc[s[i] - 'a'] = i + 1;
        }
        int ma = 1e7; char ans;
        for(int i = 0; i < 26; i++){
            if(loc[i] < ma && visit[i] == 1){
                ma = loc[i];
            }
        }
        return ma == 1e7 ? -1: ma - 1;
    }
};
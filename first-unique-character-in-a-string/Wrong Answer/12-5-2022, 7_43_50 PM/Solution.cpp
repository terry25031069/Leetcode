// https://leetcode.com/problems/first-unique-character-in-a-string

class Solution {
public:
    int firstUniqChar(string s) {
        int ans = s.size();
        set<int>ss; ss.clear();
        for(int i = s.size() - 1; i >= 0; i--){
            if(ss.find(s[i]) == ss.end()){
                ss.insert(s[i]);
                ans = i;
            }
        }
        return (ans == s.size() ? -1: ans);
    }
};
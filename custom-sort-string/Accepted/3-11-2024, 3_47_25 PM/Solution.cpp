// https://leetcode.com/problems/custom-sort-string

class Solution {
public:
    string customSortString(string order, string s) {
        int cnt[26] = {};
        for(char ch: s) cnt[ch-'a']++;
        string ans = "";
        for(char ch: order){
            ans += string(cnt[ch-'a'], ch), cnt[ch-'a'] = 0;
        }
        for(int i = 0; i < 26; i++){
            ans += string(cnt[i], 'a'+i);
        }
        return ans;
    }
};
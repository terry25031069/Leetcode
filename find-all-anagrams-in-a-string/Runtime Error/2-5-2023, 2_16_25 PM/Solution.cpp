// https://leetcode.com/problems/find-all-anagrams-in-a-string

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans; 
        vector<int> t(26, 0), pp(26, 0);
        string ss = s.substr(0, p.size());
        for(char c: p) pp[c - 'a']++;
        for(char c: ss) t[c - 'a']++;
        for(int i = 0; i <= s.size() - p.size(); i++){
            if(pp == t) ans.push_back(i);
            if(i < s.size() - p.size()){
                t[*ss.begin() - 'a']--;
                ss.erase(ss.begin());
                ss += s[p.size() + i];
                t[s[p.size() + i] - 'a']++;
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/permutation-in-string

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        map<char, int> m;
        int l = 0, r = 0;
        if(s1.size() > s2.size()) return false;
        for(auto ch: s1) m[ch]++;
        while(r - l < s1.size() && r < s2.size()){
            if(m[s2[r]]) m[s2[r]]--, r++;
            else{
                if(l == r) l++, r++;
                else{
                    m[s2[l]]++, l++;
                    if(m[s2[r]]) r++, m[s2[r]]--;
                }
            }
        }
        if(r - l == s1.size()) return true;
        return false;
    }
};
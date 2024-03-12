// https://leetcode.com/problems/isomorphic-strings

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        map<char, int>cnts, cntt;
        for(auto i: s) cnts[i]++;
        for(auto i: t) cntt[i]++;
        if(cnts.size() != cntt.size()) return false;
        for(auto i = cntt.begin(), j = cntt.begin(); i != cntt.end(); i++, j++){
            if(i->second != j->second) return false;
        }
        return true;
    }
};
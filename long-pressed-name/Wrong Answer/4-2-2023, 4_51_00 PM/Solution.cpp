// https://leetcode.com/problems/long-pressed-name

class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        map<char, int> m1, m2;
        for(char c: name) m1[c]++;
        for(char c: typed) m2[c]++;
        if(m1.size() != m2.size()) return false;
        for(auto [k, v]: m1){
            if(v > m2[k]) return false;
        }
        return true;
    }
};
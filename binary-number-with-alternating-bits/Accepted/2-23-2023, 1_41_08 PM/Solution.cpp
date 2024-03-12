// https://leetcode.com/problems/binary-number-with-alternating-bits

class Solution {
public:
    bool hasAlternatingBits(int n) {
        string s = bitset<32>(n).to_string();
        while(s[0] == '0') s.erase(s.begin());
        if(s.size() == 1) return 1;
        for(int i = 0; i < s.size() - 1; i++){
            if(s[i] == s[i+1]) return 0;
        }
        return 1;
    }
};
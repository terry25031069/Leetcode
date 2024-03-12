// https://leetcode.com/problems/reverse-bits

class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        bitset<32>a(n);
        string s = a.to_string();
        reverse(s.begin(), s.end());
        bitset<32> ans(s);
        return ans.to_ulong();
    }
};
// https://leetcode.com/problems/longest-uncommon-subsequence-i

class Solution {
public:
    int findLUSlength(string a, string b) {
        return a == b? -1: max(a.size(), b.size()); 
    }
};
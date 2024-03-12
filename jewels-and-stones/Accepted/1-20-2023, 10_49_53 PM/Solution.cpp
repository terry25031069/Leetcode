// https://leetcode.com/problems/jewels-and-stones

class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        int ans = 0;
        map<char, bool> jew;
        for(auto c: jewels) jew[c] = 1;
        for(auto c: stones) ans += jew[c];
        return ans;
    }
};
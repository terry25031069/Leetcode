// https://leetcode.com/problems/counting-bits

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;
        for(int i = 0; i <= n; i++){
            bitset<20> tmp(i);
            ans.push_back(tmp.count());
        }
        return ans;
    }
};
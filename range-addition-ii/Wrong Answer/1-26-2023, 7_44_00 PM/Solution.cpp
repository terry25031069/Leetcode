// https://leetcode.com/problems/range-addition-ii

class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        for(auto v: ops){
            m = min(n, v[0]);
            n = min(n, v[1]);
        }
        return m * n;
    }
};
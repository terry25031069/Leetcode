// https://leetcode.com/problems/reordered-power-of-2

class Solution {
public:
    vector<int> Cnt(int n){
        vector<int>cnt(10, 0);
        string tmp = to_string(n);
        for(auto c: tmp){
            cnt[c - '0']++;
        }
        return cnt;
    }
    bool reorderedPowerOf2(int n) {
        map<vector<int>, bool>m;
        for(int i = 0; i < 31; i++){
            m[Cnt(1 << i)] = 1;
        }
        return m[Cnt(n)];
    }
};
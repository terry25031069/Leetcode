// https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        map<int, int> m;
        for(auto t: time) m[t%60]++;
        int ans = 0;
        for(int i = 1; i < 30; i++) ans += m[i] * m[60 - i];
        ans += int64_t(m[0]) * (m[0] - 1) / 2;
        ans += int64_t(m[30]) * (m[30] - 1) / 2;
        return ans;
    }
};
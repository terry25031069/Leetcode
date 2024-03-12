// https://leetcode.com/problems/non-overlapping-intervals

class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int ans = 0;
        sort(intervals.begin(), intervals.end());
        int cl = -1e6, cr = -1e6;
        for(auto v: intervals){
            int l = v[0], r = v[1];
            if(l < cr) ans++;
            else cl = l, cr = r;
        }
        return ans;
    }
};
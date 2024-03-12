// https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end());
        int curpoint = points[0][1];
        int ans = 1;
        for(auto p: points){
            if(curpoint < p[0]){
                ans++;
                curpoint = p[1];
            }
            curpoint = min(curpoint, p[1]);
        }
        return ans;
    }
};
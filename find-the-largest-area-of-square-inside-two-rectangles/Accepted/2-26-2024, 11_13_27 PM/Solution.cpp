// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles

class Solution {
public:
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        const int n = bottomLeft.size();
        int r = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                const int dx = min(topRight[i][0], topRight[j][0]) - max(bottomLeft[i][0], bottomLeft[j][0]);
                if (dx <= 0) continue;
                const int dy = min(topRight[i][1], topRight[j][1]) - max(bottomLeft[i][1], bottomLeft[j][1]);
                if (dy > 0) {
                    r = max(r, min(dx, dy));
                }
            }
        }
        return static_cast<long long>(r) * r;
        
    }
};
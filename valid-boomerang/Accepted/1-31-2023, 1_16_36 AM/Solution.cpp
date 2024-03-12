// https://leetcode.com/problems/valid-boomerang

class Solution {
public:
    bool isBoomerang(vector<vector<int>>& points) {
        vector<int>v1, v2;
        v1 = {points[2][0] - points[0][0], points[2][1] - points[0][1]};
        v2 = {points[1][0] - points[0][0], points[1][1] - points[0][1]};
        return v1[0] * v2[1] - v2[0] * v1[1];
    }
};
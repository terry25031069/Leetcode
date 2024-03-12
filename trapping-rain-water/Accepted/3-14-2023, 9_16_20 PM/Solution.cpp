// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        vector<int> lmax(height.size(), -1), rmax(height.size(), -1);
        lmax[0] = height[0];
        for(int i = 1; i < height.size(); i++) lmax[i] = max(lmax[i-1], height[i]);
        rmax.back() = height.back();
        for(int i = height.size() - 2; i > -1; i--) rmax[i] = max(rmax[i+1], height[i]);
        for(int i = 1; i < height.size(); i++){
           if(lmax[i] <= height[i] || rmax[i] <= height[i]) continue;
           ans += min(lmax[i], rmax[i]) - height[i];
        }
        return ans;
    }
};
// https://leetcode.com/problems/container-with-most-water

class Solution {
public:
    int maxArea(vector<int>& height) {
        int ans = 0;
        int left = 0, right = height.size() - 1;
        while(left < right){
            ans = max(ans, min(height[left], height[right]) * (right - left));
            height[left] > height[right] ? right--: left++;
        }
        return ans;
    }
};
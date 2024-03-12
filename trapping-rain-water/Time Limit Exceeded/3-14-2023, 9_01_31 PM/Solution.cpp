// https://leetcode.com/problems/trapping-rain-water

class Solution {
public:
    int trap(vector<int>& height) {
        int ans = 0;
        for(int i = 1; i < height.size(); i++){
           int lmax = -1, rmax = -1, lidx = i - 1, ridx = i + 1;
           while(lidx > -1) lmax = max(lmax, height[lidx--]);
           while(ridx < height.size()) rmax = max(rmax, height[ridx++]);
           if(lmax <= height[i] || rmax <= height[i]) continue;
           //cout << i << ' ' << lmax << ' ' << rmax << endl;
           ans += min(lmax, rmax) - height[i];
        }
        return ans;
    }
};
// https://leetcode.com/problems/jump-game

class Solution {
public:
    bool canJump(vector<int>& nums) {
       int ans = 0;
       for(int i = 0; i < nums.size() - 1; i++){
           //cout << ans << ' ' << i << ' ' << nums[i] << endl;
           if(ans == i && nums[i] == 0) return false;
           ans = max(ans, nums[i] + i);

       }
       return ans >= nums.size() - 1;
    }
};
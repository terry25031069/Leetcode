// https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        map<int, pair<int, int>>m; m.clear();
        int curNum = -1, low = -1, high = -1;
        for(int i = 0; i < nums.size(); i++){
            if(curNum != nums[i]){
                m[curNum] = {low, high};
                curNum = nums[i], low = high = i;
            }else{
                high++;
            }
        }
        vector<int>ans;
        if(m[target] == pair<int, int>{0, 0}){
            ans = {-1, -1};
        }else{
            ans = {m[target].first, m[target].second};
        }
        return ans;
    }
};
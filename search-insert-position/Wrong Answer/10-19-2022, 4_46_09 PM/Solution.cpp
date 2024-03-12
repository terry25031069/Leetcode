// https://leetcode.com/problems/search-insert-position

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0, r = nums.size(), m;
        while(l < r){
            m = l + r >> 1;
            if(nums[m] == target) return m;
            else if(nums[m] > target) r = m - 1;
            else l = m + 1;
        }
        m = l + r >> 1;
        if(m < 0) m = 0;
        cout << l << r << endl;
        return m;
    }
};
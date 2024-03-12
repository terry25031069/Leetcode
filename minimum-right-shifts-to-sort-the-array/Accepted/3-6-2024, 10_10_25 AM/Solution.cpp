// https://leetcode.com/problems/minimum-right-shifts-to-sort-the-array

class Solution {
public:
    int minimumRightShifts(vector<int>& nums) {
        int minIndex= min_element(nums.begin(), nums.end()) - nums.begin();
        int n = nums.size();
        cout << minIndex << endl;
        for(int i = minIndex, cnt = 0; cnt < n - 1; i = (i + 1) % n, cnt++){
            if(nums[(i + 1) % n] < nums[i]) return -1;
        }
        return minIndex == 0? 0: n - minIndex;
    }
};
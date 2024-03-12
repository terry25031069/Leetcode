// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1 || nums[0] != nums[1]) return nums[0];
        if(nums[nums.size() - 2] != nums.back()) return nums.back();
        int l = 1, r = nums.size() / 2, m;
        while(l <= r){
            m = l + (r - l) / 2;
            //cout << m << ' ' << nums[2*m-1] << ' ' << nums[2*m] << ' ' << nums[2*m+1] << endl;
            if(nums[2*m] != nums[2*m+1]){
                if(nums[2*m-1] != nums[2*m]) return nums[2*m];
                else r = m - 1;
            }else l = m + 1;
        }
        return nums[2*m];
    }
};
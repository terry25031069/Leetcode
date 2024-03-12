// https://leetcode.com/problems/single-element-in-a-sorted-array

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        int l = 0, r = nums.size() / 2 - 1, m;
        while(l <= r){
            m = (r + l) / 2;
            //cout << m << ' ' << nums[2*m] << ' ' << nums[2*m+1] <<' ' << endl;
            if(nums[2*m] == nums[2*m+1]) l = m + 1;
            else r = m - 1;
        }
        for(int i = m; i < nums.size() - 1; i++){
            if(nums[i] != nums[i+1]) return nums[i+1]; 
        }
        return -1;
    }
};
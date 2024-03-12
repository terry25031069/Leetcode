// https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 0, cur = -1e5, cnt = 0;
        while(idx < nums.size()){
            if(cur ^ nums[idx]){
                cur = nums[idx], cnt = 1;
                idx++;
            }else{
                if(cnt == 1) idx++, cnt++;
                else nums.erase(nums.begin() + idx);
            }
        }
        return nums.size();
    }
};
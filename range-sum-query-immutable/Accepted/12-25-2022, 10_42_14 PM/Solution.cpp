// https://leetcode.com/problems/range-sum-query-immutable

class NumArray {
public:
    vector<int> tmp;
    NumArray(vector<int>& nums) {    
        tmp.push_back(0);
        for(int i = 0; i < nums.size(); i++){
            tmp.push_back(nums[i]);
            tmp[i + 1] += tmp[i];
        }
    }
    
    int sumRange(int left, int right) {
        return tmp[right + 1] - tmp[left];
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */
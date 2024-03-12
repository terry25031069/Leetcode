// https://leetcode.com/problems/shuffle-an-array

class Solution {
public:
    vector<int> arr, tmp;
    Solution(vector<int>& nums) {
        arr = tmp = nums;
    }
    
    vector<int> reset() {
        tmp = arr;
        return tmp;
    }
    
    vector<int> shuffle() {
        for(int i = 0; i < tmp.size(); i++){
            int ran = rand() % (tmp.size() - i) + i;
            swap(tmp[i], tmp[ran]);
        }
        return tmp;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
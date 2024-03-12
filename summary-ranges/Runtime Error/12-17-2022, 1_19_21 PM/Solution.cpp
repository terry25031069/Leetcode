// https://leetcode.com/problems/summary-ranges

class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        vector<string> ans;
        if(nums.size() == 0) return ans;
        if(nums.size() == 1){
            ans.push_back(to_string(nums[0]));
            return ans;
        }
        nums.push_back(nums.back());
        int front = nums.front(), back = front;
        for(int i = 1; i < nums.size(); i++){
            if(int64_t(nums[i]) == int64_t(back + 1)) back++;
            else{
                if(front == back){
                    ans.push_back(to_string(front));
                }else{
                    ans.push_back(to_string(front) + "->" + to_string(back));
                }
                front = back = nums[i];
            }
        }
        return ans;
    }
};
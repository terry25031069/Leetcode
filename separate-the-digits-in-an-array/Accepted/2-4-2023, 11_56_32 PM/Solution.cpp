// https://leetcode.com/problems/separate-the-digits-in-an-array

class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(auto i: nums){
            if(i < 10) ans.push_back(i);
            else{
                auto tmp = to_string(i);
                for(auto c: tmp){
                    ans.push_back(c - '0');
                }
            }
        }
        return ans;
    }
};
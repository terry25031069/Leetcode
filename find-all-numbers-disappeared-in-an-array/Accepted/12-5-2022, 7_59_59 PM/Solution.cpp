// https://leetcode.com/problems/find-all-numbers-disappeared-in-an-array

class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int a[200000] = {};
        vector<int> ans;
        for(auto i: nums)a[i]++;
        for(int i = 1; i <= nums.size(); i++){
            if(a[i] == 0){
                ans.push_back(i);
            }
        }
        return ans;
    }
};
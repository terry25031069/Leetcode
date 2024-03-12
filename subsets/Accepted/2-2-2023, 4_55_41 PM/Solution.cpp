// https://leetcode.com/problems/subsets

class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> s;
        vector<vector<int>> ans;
        for(int i = 0; i < (1 << nums.size()); i++){
            bitset<10> b(i);
            vector<int> tmp;
            for(int i = 0; i < nums.size(); i++){
                if(b[i]) tmp.push_back(nums[i]);
            }
            if(s.find(tmp) == s.end()) ans.push_back(tmp);
        }
        return ans;
    }
};
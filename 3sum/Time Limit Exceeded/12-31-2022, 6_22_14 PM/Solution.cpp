// https://leetcode.com/problems/3sum

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        set<vector<int>> s;
        map<int, int> idx; 
        for(int i = 0; i < nums.size(); i++){
            idx[nums[i]] = i + 1;
        }
        for(int i = 0; i < nums.size() - 2; i++){
            for(int j = i + 1; j < nums.size() - 1; j++){
                if(idx[0 - nums[i] - nums[j]]){
                    int tmp = idx[0 - nums[i] - nums[j]];
                    if(tmp == i + 1 || tmp == j + 1) continue;
                    vector<int> v = {nums[i], nums[j],  0 - nums[i] - nums[j]};
                    sort(v.begin(), v.end());
                    if(s.find(v) == s.end()){
                        s.insert(v);
                        ans.push_back(v);
                    }
                }
            }
        }
        return ans;
    }
};
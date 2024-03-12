// https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions

class Solution {
public:
    map<int, int> m;
    vector<vector<int>> findMatrix(vector<int>& nums) {
        vector<vector<int>> ans;
        for(int i: nums) m[i]++;
        for(auto [k, v]: m){
            if(ans.size() < v) ans.resize(v);
            for(int i = 0; i < v; i++){
                ans[i].push_back(k);
            }
        }
        return ans;
    }
};
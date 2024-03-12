// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ans{{1}};
        for(int i = 0; i < numRows - 1; i++){
            vector<int> tmp{1, 1};
            for(int j = 0; j < ans.back().size() - 1; j++){
                tmp.insert(tmp.end() - 1, ans.back()[j] + ans.back()[j + 1]);
            }
            ans.emplace_back(tmp);
        }
        return ans;
    }
};
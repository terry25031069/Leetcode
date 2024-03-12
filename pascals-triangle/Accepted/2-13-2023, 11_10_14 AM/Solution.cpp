// https://leetcode.com/problems/pascals-triangle

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> tmp{1};
        vector<vector<int>> ans{tmp};
        for(int i = 2; i <= numRows; i++){
            tmp.insert(tmp.begin(), 0);
            for(int i = 0; i < tmp.size() - 1; i++){
                tmp[i] += tmp[i + 1];
            }
            ans.push_back(tmp);
        }
        return ans;
    }
};
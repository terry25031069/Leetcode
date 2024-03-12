// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        for(int i = 0; i < rowIndex; i++){
            ans.push_back(0);
            for(int j = ans.size() - 1; j > 0; j--) ans[j] += ans[j-1];
        }
        return ans;
    }
};
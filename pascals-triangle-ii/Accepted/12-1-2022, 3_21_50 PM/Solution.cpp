// https://leetcode.com/problems/pascals-triangle-ii

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ans = {1};
        while(rowIndex--){
            for(int i = ans.size() - 1; i  > 0; i--){
                ans[i] += ans[i - 1];
            }
            ans.push_back(1);
        }
        return ans;
    }
};
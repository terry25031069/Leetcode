// https://leetcode.com/problems/combinations

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int n, int k, int start, vector<int>tmp){
        if(k == 0){
            ans.push_back(tmp);
        }
        for(int i = start; i <= n; i++){
            tmp.push_back(i);
            dfs(n, k-1, i + 1, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        dfs(n, k, 1, {});
        return ans;
    }
};
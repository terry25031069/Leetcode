// https://leetcode.com/problems/combination-sum

class Solution {
public:
    vector<vector<int>> ans{};
    void dfs(vector<int>& candidates, int bas, int target, vector<int>tmp){
        if(target == 0){
            ans.push_back(tmp);
            return;
        }
        if(target < 0 || bas == candidates.size()) return;  
        dfs(candidates, bas + 1, target, tmp);
        int currentNum = candidates[bas];
        for(int i = 1; i * currentNum <= target; i++){
            tmp.push_back(currentNum);
            for(int i = 0; i < tmp.size(); i++) cout << tmp[i] << " \n"[i == tmp.size() - 1];
            dfs(candidates, bas + 1, target - i * currentNum, tmp);
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>tmp{};
        dfs(candidates, 0, target, tmp);
        return ans;
    }
};
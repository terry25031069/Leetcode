// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> ans;
    set<vector<int>> s;
    void dfs(int idx, int target, vector<int> &arr, vector<int> tmp){
        cout << idx << ' ' << target << endl;
        if(target == 0){
            if(s.find(tmp) == s.end()){
                ans.push_back(tmp);
                s.insert(tmp);
            }
        }else{
            if(idx == arr.size() || target < 0) return;
            if(target >= arr[idx]){
                auto ttmp = tmp; ttmp.push_back(arr[idx]);
                dfs(idx + 1, target - arr[idx], arr, ttmp);
            }
            dfs(idx + 1, target, arr, tmp);
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        dfs(0, target, candidates, {});
        return ans;
    }
};
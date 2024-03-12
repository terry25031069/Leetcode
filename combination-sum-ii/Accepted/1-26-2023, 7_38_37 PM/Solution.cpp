// https://leetcode.com/problems/combination-sum-ii

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int idx, int target, vector<int> &arr, vector<int> &tmp){
        //for(auto i: tmp) cout << i << ' '; cout << endl;
        if(target == 0){
            ans.push_back(tmp);
            return;
        }
        for(int i = idx; i < arr.size(); i++){
            if(i > idx && arr[i] == arr[i - 1]) continue;
            if(target >= arr[i]){
                tmp.push_back(arr[i]);
                dfs(i + 1, target - arr[i], arr, tmp);
                tmp.pop_back();
            }
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> emp;
        dfs(0, target, candidates, emp);
        return ans;
    }
};
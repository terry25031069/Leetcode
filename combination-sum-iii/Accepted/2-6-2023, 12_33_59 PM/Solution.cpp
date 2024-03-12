// https://leetcode.com/problems/combination-sum-iii

class Solution {
public:
    vector<vector<int>> ans;
    void dfs(int k, int n, vector<int> &arr){
        if(k == 0){
            if(n == 0) ans.push_back(arr);
        }else{
            int t = 1;
            if(arr.size()) t = arr.back() + 1; 
            for(int i = t; i < 10; i++){
                if(n >= i){
                    arr.push_back(i);
                    dfs(k - 1, n - i, arr);
                    arr.pop_back();
                }else break;
            }
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        if(n <( k * k - k) / 2) return {};
        vector<int> tmp;
        dfs(k, n, tmp);
        return ans;
    }
};
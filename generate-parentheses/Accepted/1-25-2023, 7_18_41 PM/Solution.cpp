// https://leetcode.com/problems/generate-parentheses

class Solution {
public:
    vector<string> ans;
    void dfs(int l, int r, int n, string s){
        if(r == n) ans.push_back(s);
        if(l < n) dfs(l + 1, r, n, s + '(');
        if(r < l) dfs(l, r + 1, n, s + ')');
    }
    vector<string> generateParenthesis(int n) {
        dfs(0, 0, n, "");
        return ans;
    }
};
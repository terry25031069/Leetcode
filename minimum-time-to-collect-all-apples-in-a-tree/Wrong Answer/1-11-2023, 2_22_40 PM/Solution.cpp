// https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree

class Solution {
public:
    map<int, vector<int>> m;
    vector<bool> Apple;
    int dfs(int root){
        int ans = (Apple[root]) * 2;
        bool check = 0;
        for(auto e: m[root]){
            int tmp = dfs(e);
            ans += tmp, check |= tmp;
        }
        return ans + (check && !Apple[root]) * 2;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        for(int i = 0; i < edges.size(); i++){
            auto &v = edges[i];
            m[v[0]].push_back(v[1]);
        }
        Apple = hasApple;
        int ans = dfs(0);
        if(!ans) return 0;
        return ans - 2;
    }
};
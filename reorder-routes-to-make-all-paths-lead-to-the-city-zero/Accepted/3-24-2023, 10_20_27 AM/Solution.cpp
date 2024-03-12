// https://leetcode.com/problems/reorder-routes-to-make-all-paths-lead-to-the-city-zero

class Solution {
public:
    vector<vector<int>> e;
    set<vector<int>> s;
    int ans = 0;
    void dfs(int prev, int cur){
        for(auto ele: e[cur]){
            if(ele != prev){
                if(s.find({ele, cur}) == s.end()) ans++;
                dfs(cur, ele);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        e.resize(n);
        for(auto v: connections){
            e[v[0]].push_back(v[1]);
            e[v[1]].push_back(v[0]);
            s.insert(v);
        }
        dfs(0, 0);
        return ans;
    }
};
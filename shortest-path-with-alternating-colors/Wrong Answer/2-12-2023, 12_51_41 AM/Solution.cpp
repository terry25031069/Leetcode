// https://leetcode.com/problems/shortest-path-with-alternating-colors

class Solution {
public:
    using pii = pair<int, int>;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> re(n), be(n);
        for(auto v: redEdges) re[v[0]].push_back(v[1]);
        for(auto v: blueEdges) be[v[0]].push_back(v[1]);
        vector<int> ans(n, 1e8); ans[0] = 0;
        queue<pii> q; q.push({0, -1});
        while(!q.empty()){
            pii t = q.front(); q.pop();
            if(t.second != 0){
                for(auto e: re[t.first]){
                    if(ans[e] == 1e8){
                        ans[e] = ans[t.first] + 1;
                        q.push({e, 0});
                    }
                }
            }
            if(t.second != 1){
                for(auto e: be[t.first]){
                    if(ans[e] == 1e8){
                        ans[e] = ans[t.first] + 1;
                        q.push({e, 1});
                    }
                }
            }
        }
        for(auto &i: ans){
            if(i == 1e8) i = -1;
        }
        return ans;
    }
};
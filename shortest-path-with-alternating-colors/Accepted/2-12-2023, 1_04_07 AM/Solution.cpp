// https://leetcode.com/problems/shortest-path-with-alternating-colors

class Solution {
public:
    using pii = pair<int, int>;
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>> re(n), be(n);
        for(auto v: redEdges) re[v[0]].push_back(v[1]);
        for(auto v: blueEdges) be[v[0]].push_back(v[1]);
        vector<pii> ans(n, {1e8, 1e8}); ans[0] = {0, 0};
        queue<pii> q; q.push({0, -1});
        while(!q.empty()){
            pii t = q.front(); q.pop();
            if(t.second != 0){
                for(auto e: re[t.first]){
                    if(ans[e].first == 1e8){
                        ans[e].first = ans[t.first].second + 1;
                        q.push({e, 0});
                    }
                }
            }
            if(t.second != 1){
                for(auto e: be[t.first]){
                    if(ans[e].second == 1e8){
                        ans[e].second = ans[t.first].first + 1;
                        q.push({e, 1});
                    }
                }
            }
        }
        vector<int> anss;
        for(auto v: ans){
            if(v.first == 1e8 && v.second == 1e8) anss.push_back(-1);
            else anss.push_back(min(v.first, v.second));
        }
        return anss;
    }
};
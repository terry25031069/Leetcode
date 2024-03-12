// https://leetcode.com/problems/minimum-fuel-cost-to-report-to-the-capital

class Solution {
public:
    long long ans = 0;
    vector<bool> visit;
    int dfs(vector<vector<int>>& v, int node, int seats){
        visit[node] = 1;
        int cnt = 1;
        for(auto e: v[node]){
            if(!visit[e])
                cnt += dfs(v, e, seats);
        }
        if(node) ans += (cnt / seats) + (cnt % seats != 0);
        return cnt;
    }
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
    vector<vector<int>> v(roads.size() + 1);
    visit.resize(roads.size() + 1, 0);
    for(auto vec: roads){
        v[vec[0]].push_back(vec[1]);
        v[vec[1]].push_back(vec[0]);
    }
    dfs(v, 0, seats);
    return ans;   
    }
};
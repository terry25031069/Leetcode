// https://leetcode.com/problems/all-paths-from-source-to-target

class Solution {
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        using piv = pair<int, vector<int>>;
        vector<vector<int>> ans;
        queue<piv> q; q.push({0, {0}});
        while(!q.empty()){
            auto top = q.front(); q.pop();
            for(auto i: graph[top.first]){
                auto ansUnit = top.second;
                ansUnit.push_back(i);
                if(i == graph.size() - 1){
                    ans.push_back(ansUnit);
                }else{
                    q.push({i, ansUnit});
                }
            }
        }
        return ans;
    }
};
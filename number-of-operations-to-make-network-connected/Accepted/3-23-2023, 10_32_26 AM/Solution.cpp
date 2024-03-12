// https://leetcode.com/problems/number-of-operations-to-make-network-connected

class Solution {
public:
    vector<bool> visit;
    vector<vector<int>> edge;

    void dfs(int v){
        for(int nv: edge[v]){
            if(!visit[nv]) visit[nv] = 1, dfs(nv);
        }
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        visit.resize(n, 0);
        edge.resize(n);
        for(auto v: connections){
            edge[v[0]].push_back(v[1]);
            edge[v[1]].push_back(v[0]);
        }
        int con = 0;
        for(int i = 0; i < n; i++){
            if(!visit[i]) visit[i], dfs(i), con++;
        }
        //cout << con << endl;
        return con - 1;
    }
};
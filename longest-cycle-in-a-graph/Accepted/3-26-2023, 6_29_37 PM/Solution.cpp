// https://leetcode.com/problems/longest-cycle-in-a-graph

class Solution {
public:
    vector<int> indeg, visit;
    int bfs(int v, vector<int>& edges){
        int step = 0;
        while(1){
            if(visit[v]) return step;
            visit[v] = 1, v = edges[v];
            step++;
        }
        return -1;
    }
    int longestCycle(vector<int>& edges) {
        int ans = 0;
        int n = edges.size();
        indeg.resize(n, 0), visit.resize(n, 0);
        queue<int> q;
        for(int e: edges) if(e != -1) indeg[e]++;
        for(int i = 0; i < n; i++){
            if(!indeg[i]) q.push(i);
        }
        while(!q.empty()){
            int e = edges[q.front()]; q.pop();
            if(e == -1) continue;
            indeg[e]--;
            if(!indeg[e]) q.push(e);
        }
        if(*max_element(indeg.begin(), indeg.end()) == 0) return -1;
        for(int i = 0; i < n; i++){
            if(!indeg[i] || visit[i]) continue;
            int tmp = bfs(i, edges);
            ans = max(ans, tmp);
        }
        
        return ans;
    }
};
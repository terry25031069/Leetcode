// https://leetcode.com/problems/longest-cycle-in-a-graph

class Solution {
public:
    vector<int> indeg, visit;
    int bfs(int v, vector<int>& edges){
        int step = 0;
        while(1){
            if(visit[v]) break;
            visit[v] = 1, v = edges[v];
            step++;
        }
        return step;
    }
    int longestCycle(vector<int>& edges) {
        int ans = 0;
        // 因為 edges 裡面代表 idx 會指向哪，所以 size 會剛好 = |v|
        int n = edges.size();
        indeg.resize(n, 0), visit.resize(n, 0);
        queue<int> q;
        // 注意 e 不要 = -1 ，否則會越界！
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
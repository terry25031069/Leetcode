// https://leetcode.com/problems/minimum-reverse-operations

class Solution {
public:
    vector<int> minReverseOperations(int n, int p, vector<int>& banned, int k) {
        unordered_set<int> s;
        for(int i: banned) s.insert(i);
        vector<int> ans(n, -1), visit(n, 0); ans[p] = 0;
        queue<int> q; q.push(p); visit[p] = 1;
        while(!q.empty()){
            int t = q.front(); q.pop();
            int ini = t - k + 1;
            for(int idx = max(0, ini); idx <= t; idx++){
                int p = idx - ini, loc = ini + 2 * p;
                if(loc > -1 && loc < n && idx + k - 1  < n && s.find(loc) == s.end() && !visit[loc]){
                    ans[loc] = ans[t] + 1;
                    q.push(loc);
                    visit[loc] = 1;
                }
            }
        }
        return ans;
    }
};
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
            for(int i = k % 2 + 1; i < k; i += 2){
                if(t - i > -1 && s.find(t - i) == s.end() && !visit[t - i]){
                    ans[t - i] = ans[t] + 1;
                    q.push(t - i);
                    visit[t - i] = 1;
                }
                if(t + i < n && s.find(t + i) == s.end() && !visit[t + i]){
                    ans[t + i] = ans[t] + 1;
                    q.push(t + i);
                    visit[t + i] = 1;
                }
            }
        }
        return ans;
    }
};
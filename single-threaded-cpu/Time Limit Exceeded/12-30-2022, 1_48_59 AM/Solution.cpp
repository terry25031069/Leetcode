// https://leetcode.com/problems/single-threaded-cpu

struct taskCmp{
    bool operator () (vector<int> a, vector<int> b){
        if(a[1] != b[1]) return a[1] > b[1];
        return a[2] > b[2];
    }
};

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        for(int i = 0; i < tasks.size(); i++){
            tasks[i].push_back(i);
        }
        sort(tasks.begin(), tasks.end());
        vector<int> ans;
        int idx = 1;
        int curTime = tasks[0][0];
        priority_queue<vector<int>, vector<vector<int>>, taskCmp>q; 
        q.push(tasks[0]);
        while(!q.empty()){
            auto top = q.top(); q.pop(); 
            ans.push_back(top[2]);
            curTime = min(1000000000, max(top[0], curTime) + top[1]);
            while(idx < tasks.size() && (q.empty() || curTime >= tasks[idx][0])){
                q.push(tasks[idx++]);
            }
        }
        return ans;
    }
};
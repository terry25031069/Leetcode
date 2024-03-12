// https://leetcode.com/problems/single-threaded-cpu

struct task{
    vector<int> time;
    int num;
    task(vector<int> time, int num):time(time), num(num){};
};
static bool cmp(task a, task b){
    if(a.time[0] != b.time[0])return a.time[0] < b.time[0];
    return a.time[1] < b.time[1];
}
bool operator < (task a, task b){
    if(a.time[1] != b.time[1]) return a.time[1] > b.time[1];
    return a.time[0] > b.time[0];
}

class Solution {
public:
    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<task> T;
        for(int i = 0; i < tasks.size(); i++){
            T.push_back(task(tasks[i], i));
        }
        sort(T.begin(), T.end(), cmp);
        vector<int> ans;
        int idx = 1, curTime = T[0].time[0];
        priority_queue<task> q; q.push(T[0]);
        while(!q.empty()){
            auto top = q.top(); q.pop(); 
            cout << top.time[0] << ' ' << top.time[1] << endl;
            ans.push_back(top.num);
            curTime += top.time[1];
            while(idx < T.size() && (q.empty() || curTime >= T[idx].time[0])){
                cout << idx << endl;
                q.push(T[idx++]);
            }
        }
        return ans;
    }
};
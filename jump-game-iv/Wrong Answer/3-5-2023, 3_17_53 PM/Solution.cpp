// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    int minJumps(vector<int>& arr) {
        if(arr.size() == 1) return 0;
        int visit[arr.size()]; memset(visit, 0, sizeof(visit));
        unordered_map<int, vector<int>> m; 
        for(int i = arr.size()-1; i > 0; i--) m[arr[i]].push_back(i);
        queue<int> q; q.push(0), visit[0] = 1;
        for(int j = 0; !q.empty(); j++){
            for(int i = q.size(); i > 0; i--){
                int f = q.front(); q.pop();
                if(f + 1 < arr.size()){
                    if(f + 2 == arr.size()) return j + 1;
                    if(!visit[f+1])q.push(f+1), visit[f+1] = 1;
                }
                if(f - 1 >= 0){
                    if(!visit[f-1])q.push(f-1), visit[f-1] = 1;
                }
                for(int idx: m[arr[f]]){
                    if(idx == arr.size() - 1) return j + 1;
                    if(!visit[idx])q.push(idx), visit[idx] = 1;
                }
                m.erase(f);
            }
        }
        return -1;
    }
};
// https://leetcode.com/problems/jump-game-iv

class Solution {
public:
    int minJumps(vector<int>& arr) {
        vector<int> dis(arr.size() + 1, 5e5); dis[0] = 0;
        map<int, vector<int>> m; 
        for(int i = 0; i < arr.size(); i++) m[arr[i]].push_back(i);
        // for(auto [k, v]: m){
        //     cout << k << ": ";
        //     for(auto idx: v) cout << idx << ' '; cout << endl;
        // }
        // cout << "------------\n";
        queue<int> q; q.push(0);
        for(int i = q.size(); i >= 0; i--){
            while(!q.empty()){
                int f = q.front(); q.pop();
                if(f + 1 < arr.size()){
                    dis[f+1] = min(dis[f+1], dis[f] + 1);
                    if(f + 2 == arr.size()) return dis[f+1];
                    cout << f+1 << ' ' << arr[f+1] << ' ' << dis[f+1] << endl;
                    q.push(f+1);
                }
                if(f - 1 >= 0){
                    dis[f-1] = min(dis[f-1], dis[f] + 1);
                    cout << f-1 << ' ' << arr[f-1] << ' ' << dis[f-1] << endl;
                    q.push(f-1);
                }
                for(auto idx: m[arr[f]]){
                    if(idx - f){
                        dis[idx] = min(dis[idx], dis[f] + 1);
                        if(idx == arr.size() - 1) return dis[idx];
                        cout << idx << ' ' << arr[idx] << ' ' << dis[idx] << endl;
                        q.push(idx);
                    }
                }
            }
        }
        return 0;
    }
};
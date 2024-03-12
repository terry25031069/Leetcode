// https://leetcode.com/problems/jump-game-iii

class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        vector<bool> b(arr.size(), 0); b[start] = 1;
        queue<int> q; q.push(start);
        while(!q.empty()){
            int t = q.front(); q.pop();
            if(t + arr[t] < arr.size() && !b[t + arr[t]]){
                q.push(t + arr[t]), b[t + arr[t]] = 1;
            }
            if(t - arr[t] > -1 && !b[t - arr[t]]){
                q.push(t - arr[t]), b[t - arr[t]] = 1;
            }
        }
        bool ans = 1;
        for(int i = 0; i < arr.size(); i++){
            if(!arr[i]){
                ans &= b[i];
            }
        }
        return ans;
    }
};
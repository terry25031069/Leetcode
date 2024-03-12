// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    vector<int> node[2001];
    int tag[2001] = {};
    bool dfs(int parent, int cur){
        if(parent == cur) tag[cur] = 1;
        for(auto i: node[cur]){
            if(tag[i] == 3 - tag[cur]) continue;
            else if(tag[i] && 3 - tag[cur] != tag[i]){
                return false;
            }
            else{
                tag[i] = 3 - tag[cur];
                dfs(cur, i);
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        for(auto v: dislikes){
            node[v[0]].push_back(v[1]);
            node[v[1]].push_back(v[0]);
        }
        bool ans = true;
        for(auto v: dislikes){
            if(!tag[v[0]])ans &= dfs(v[0], v[0]);
            cout << ans << endl;
        }
        return ans;
    }
};
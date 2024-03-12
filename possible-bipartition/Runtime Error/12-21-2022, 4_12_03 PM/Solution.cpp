// https://leetcode.com/problems/possible-bipartition

class Solution {
public:
    vector<int> node[2001];
    int tag[2001] = {};
    bool dfs(int parent, int cur){
        cout << parent << ' ' << cur << endl;
        for(auto i: node[cur]){
            if(tag[i] == 3 - tag[cur]) continue;
            else if(!tag[i]){
                tag[i] = 3 - tag[cur];
                dfs(cur, i);
            }
            else{
                return false;
            }
        }
        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        for(auto v: dislikes){
            node[v[0]].push_back(v[1]);
            node[v[1]].push_back(v[0]);
        }
        for(int i = 1; i <= n; i++){
            if(node[i].size()){
                cout << i << ": ";
                for(int j: node[i]) cout << j << ' '; cout << endl;
            }
        }
        tag[dislikes[0][0]] = 1;
        return dfs(dislikes[0][0], dislikes[0][0]);
    }
};
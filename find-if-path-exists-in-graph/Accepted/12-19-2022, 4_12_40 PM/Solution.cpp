// https://leetcode.com/problems/find-if-path-exists-in-graph

class Solution {
public:
    int p[200001];
    int find(int i){
        return p[i] == i? i: p[i] = find(p[i]);
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        for(int i = 0; i < 200001; i++){
            p[i] = i;
        }
        for(auto i: edges){
            int a = i[0], b = i[1];
            p[find(a)] = p[find(b)];
        }
        return find(source) == find(destination);
    }
};
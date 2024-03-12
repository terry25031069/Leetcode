// https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph

class Solution {
public:
    vector<int> p;
    int find(int n){
        return (p[n] == n? n: p[n] = find(p[n]));
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        p.resize(n);
        for(int i = 0; i < n; i++) p[i] = i;
        for(auto v: edges){
            int pa = find(v[0]), pb = find(v[1]);
            if(pa != pb){
                p[pb] = pa;
            }
        }
        map<int, int> m;
        for(int i = 0; i < n; i++){
            p[i] = find(p[i]);
            //cout << i << ' ' << p[i] << endl;
            m[p[i]]++;
        }
        long long ans = (int64_t)n * (n - 1) / 2;
        for(auto [k, v]: m) ans -= (int64_t)v * (v - 1) / 2;
        return ans;
    }
};
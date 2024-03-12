// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

class Solution {
public:
    vector<vector<int>> v;
    vector<int> ans;
    string s;
    vector<int> mge(vector<int> &a, vector<int> b){
        for(int i = 0; i < 26; i++){
            a[i] += b[i];
        }
        return a;
    }
    vector<int> dfs(int prev, int cur){
        vector<int> cnt(26, 0); cnt[s[cur] - 'a']++;
        for(auto e: v[cur]){
            if(e != prev){
                mge(cnt, dfs(cur, e));
            }
        }
        ans[cur] = cnt[s[cur] - 'a'];
        return cnt;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string label) {
        v.resize(n);
        ans.resize(n);
        s = label;
        for(auto e: edges){
            int n1 = e[0], n2 = e[1];
            v[n1].push_back(n2);
            v[n2].push_back(n1);
        }
        dfs(0, 0);
        return ans;
    }
};
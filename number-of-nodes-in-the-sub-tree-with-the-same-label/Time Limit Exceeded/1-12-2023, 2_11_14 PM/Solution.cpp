// https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label

class Solution {
public:
    using mci = map<char, int>;
    vector<vector<int>> v;
    vector<int> ans;
    string s;
    map<char, int> mge(mci &a, mci b){
        for(auto &[k, v]: b){
            a[k] += v;
        }
        return a;
    }
    map<char, int> dfs(int prev, int cur){
        map<char, int> cnt;
        cnt[s[cur]]++;
        for(auto e: v[cur]){
            if(e != prev){
                mge(cnt, dfs(cur, e));
            }
        }
        ans[cur] = cnt[s[cur]];
        //cout << cur << ' ' << ans[cur] << endl;
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
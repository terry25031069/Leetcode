// https://leetcode.com/problems/longest-path-with-different-adjacent-characters

class Solution {
public:
    using pii = pair<int, int>;
    vector<vector<int>> v;
    string s;
    int ans = 0;
    pii dfs(int root){
        pii p = {0, 0};
        for(auto i: v[root]){
            if(s[i] != s[root]){
                int tmp = dfs(i).first + 1;
                if(tmp > p.first) p.second = p.first, p.first = tmp;
                else if(tmp > p.second) p.second = tmp;
            }
        }
        ans = max(ans, p.first + p.second + 1);
        return p;
    }
    int longestPath(vector<int>& parent, string ss) {
        v.resize(parent.size());
        s = ss;
        for(int i = 1; i < parent.size(); i++){
            v[parent[i]].push_back(i);
        }
        pii p = dfs(0);
        ans = max(ans, p.first + p.second + 1);
        return ans;
    }
};
// https://leetcode.com/problems/lexicographical-numbers

class Solution {
public:
    vector<int> ans;
    void dfs(string s, int n){
        if(s.size() && stoi(s) > n) return;
        for(int i = (s.size() == 0); i < 10; i++){
            string tmp = s + char('0' + i);
            if(stoi(tmp) <= n) ans.push_back(stoi(tmp));
            dfs(tmp, n);
        }
    }
    vector<int> lexicalOrder(int n) {
        dfs("", n);
        return ans;
    }
};
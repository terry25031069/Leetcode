// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, j = 0;
        for(int i = 0; i < s.size(); i++){
            if(j >= g.size()) break;
            if(g[j] > s[i]) continue;
            else j++, ans++;
        }
        return ans;
    }
};
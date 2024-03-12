// https://leetcode.com/problems/assign-cookies

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int ans = 0, j = 0, gn = g.size(), sn = s.size();
        for(int i = 0; i < sn; i++){
            if(j >= gn) break;
            if(g[j] <= s[i]) j++, ans++;
        }
        return ans;
    }
};
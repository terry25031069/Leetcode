// https://leetcode.com/problems/destination-city

class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        map<string, string> m;
        for(auto v: paths) m[v[0]] = v[1];
        string ans = paths[0][0];
        while(m[ans] != "") ans = m[ans];
        return ans;
    }
};
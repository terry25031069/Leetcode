// https://leetcode.com/problems/find-the-substring-with-maximum-cost

class Solution {
public:
    int maximumCostSubstring(string s, string chars, vector<int>& vals) {
        int ans, ma, m[129] = {};
        ans = ma = 0;
        vector<int> v;
        for(int i = 0; i < chars.size(); i++) m[chars[i]] = vals[i];
        for(auto c: s){
            int tmp = 0;
            if(!m[c]) tmp = c - 'a' + 1;
            else tmp = m[c];
            v.push_back(tmp);
        }
        for(int i: v){
            ma = max(0, ma + i);
            ans = max(ma, ans);
        }
        return ans;
    }
};
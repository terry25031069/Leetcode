// https://leetcode.com/problems/non-decreasing-subsequences

class Solution {
public:
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        set<vector<int>> s;
        vector<vector<int>> anss, ans;
        for(auto i: nums){
            int n = anss.size();
            for(int idx = 0; idx < n; idx++){
                if(anss[idx].back() <= i){
                    auto tmp = anss[idx];
                    tmp.push_back(i);
                    if(s.find(tmp) == s.end()) anss.push_back(tmp), s.insert(tmp);
                }
            }
            if(s.find({i}) == s.end()) anss.push_back({i}), s.insert({i});
        }
        for(auto v: anss){
            if(v.size() > 1) ans.push_back(v);
        }
        return ans;
    }
};
// https://leetcode.com/problems/top-k-frequent-elements

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> m;
        for(auto i: nums) m[i]++;
        vector<pair<int, int>> cnt; 
        for(auto [k, v]: m) cnt.push_back({v, k});
        sort(cnt.begin(), cnt.end(), greater<pair<int, int>>());
        vector<int> ans;
        for(int i = 0; i < k; i++) ans.push_back(cnt[i].second);
        return ans;
    }
};
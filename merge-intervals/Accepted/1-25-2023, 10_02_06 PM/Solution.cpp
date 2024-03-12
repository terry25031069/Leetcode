// https://leetcode.com/problems/merge-intervals

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& ivl) {
        vector<vector<int>> ans;
        ivl.push_back({1000000, 1000000});
        sort(ivl.begin(), ivl.end());
        int l = ivl[0][0], r = ivl[0][1];
        for(int i = 1; i < ivl.size(); i++){
            if(ivl[i][0] <= r && ivl[i][1] >= r) r = ivl[i][1];
            else if(ivl[i][0] > r){
                ans.push_back({l, r});
                l = ivl[i][0], r = ivl[i][1];
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/find-players-with-zero-or-one-losses

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int p[100001] = {}, ma = 0;
        for(auto i: matches){
            p[i[1]]++;
            ma = max(i[0], max(i[1], ma));
        }
        vector<vector<int>> ans(2);
        for(int i = 1; i <= ma; i++){
            //cout << p[i] << " \n"[i == ma];
            if(p[i] < 2) ans[p[i]].push_back(i);
        }
        return ans;
    }
};
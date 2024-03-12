// https://leetcode.com/problems/find-the-town-judge

class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> deg(n + 1, vector<int>(2));
        for(auto v: trust){
            int f = v[0], t = v[1];
            deg[f][1]++, deg[t][0]++;
        }
        for(int i = 1; i <= n; i++){
            if(deg[i][0] == n - 1 && deg[i][1] == 0) return i;
        }
        return -1;
    }
};
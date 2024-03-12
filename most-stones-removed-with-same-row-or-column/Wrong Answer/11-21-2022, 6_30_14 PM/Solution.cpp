// https://leetcode.com/problems/most-stones-removed-with-same-row-or-column

class Solution {
public:
    int p[1001] = {};

    int find(int n){
        return p[n] != n ? (p[n] = find(p[n])): n;
    }

    bool check(vector<int>x, vector<int>y){
        return (x[0] == y[0] || x[1] == y[1]);
    }

    int removeStones(vector<vector<int>>& stones) {
        for(int i = 0; i < 1001; i++) p[i] = i;
        for(int i = 0; i < stones.size() - 1; i++){
            for(int j = i + 1; j < stones.size(); j++){
                if(check(stones[i], stones[j])){
                    p[find(j)] = find(i);
                    //cout << i << ' ' << find(i) << j << ' ' << find(j) << endl;
                }
            }
        }
        set<int>ans;
        for(int i = 0; i < stones.size(); i++){
            //cout << p[i] << endl;
            ans.insert(p[i]);
        }
        return stones.size() - ans.size();
    }
};
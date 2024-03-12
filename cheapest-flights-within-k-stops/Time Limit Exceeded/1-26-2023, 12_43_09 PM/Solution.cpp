// https://leetcode.com/problems/cheapest-flights-within-k-stops

class Solution {
public:
    int N = 100000000;
    int ans = N;
    vector<vector<int>> w;
    void dfs(int src, int dst, int cur, int depth, int cost){
        if(src == dst){
            ans = min(ans, cost); return;
        }
        for(int i = 0; i < w.size(); i++){
            if(cur < depth && w[src][i]){
                //cout << src << ' ' << i << ' ' << w[src][i] << endl;
                dfs(i, dst, cur + 1, depth, cost + w[src][i]);
            }
        }
    }
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        w.resize(n, vector<int>(n, 0));
        for(auto i: flights) w[i[0]][i[1]] = i[2];
        dfs(src, dst, 0, k + 1, 0);
        if(ans == N) return -1;
        return ans;
    }
};
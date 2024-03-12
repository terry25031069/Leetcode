// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i

class Solution {
public:
    bool chk(int i, int j, auto & points){
        int xl = min(points[i][0], points[j][0]), xr = max(points[i][0], points[j][0]);
        int yl = min(points[i][1], points[j][1]), yr = max(points[i][1], points[j][1]);
        for(int x = 0; x < points.size(); x++){
            if(x == i || x == j) continue;
            int tx = points[x][0], ty = points[x][1];
            if(xl <= tx && tx <= xr && yl <= ty && ty <= yr) return false;
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        int ans = 0, n = points.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                auto &ta = min(points[i], points[j]), &tb = max(points[i], points[j]);
                if(i != j && !(ta[0] < tb[0] && ta[1] < tb[1])){
                    ans += chk(i, j, points);
                }
            }
        }
        return ans;
    }
};
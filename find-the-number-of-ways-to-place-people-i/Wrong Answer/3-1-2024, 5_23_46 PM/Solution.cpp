// https://leetcode.com/problems/find-the-number-of-ways-to-place-people-i

class Solution {
public:
    bool chk(int i, int j, auto & points){
        int xl = points[i][0], xr = points[j][0];
        int yl = points[j][1], yr = points[i][1];
        for(int x = i + 1; x < j; x++){
            int tx = points[x][0], ty = points[x][1];
            if(xl <= tx && tx <= xr && yl <= ty && ty <= yr) return false;
        }
        return true;
    }
    int numberOfPairs(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b){
            if(a[0] - a[1] != b[0] - b[1]){
                return a[0] - a[1] < b[0] - b[1];
            }
            return a < b;
        });
        int ans = 0, n = points.size();
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                if(points[i][0] - points[i][1] != points[j][0] - points[j][1]){
                    ans += chk(i, j, points);
                }
            }
        }
        return ans;
    }
};
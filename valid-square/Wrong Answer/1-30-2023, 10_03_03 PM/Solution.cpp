// https://leetcode.com/problems/valid-square

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
        vector<vector<int>> f; f.resize(4);
        f[0] = {p1[0], p1[1]}, f[1] = {p2[0], p2[1]}, f[2] = {p3[0], p3[1]},f[3] = {p4[0], p4[1]};
        double xm, ym;
        for(auto v: f){
            xm += v[0], ym += v[1];
        }
        xm /= 4, ym /= 4;
        sort(f.begin(), f.end(), [xm, ym](vector<int>a, vector<int>b){
            return atan2(a[0] - xm, a[1] - ym) < atan2(b[0] - xm, b[1] - ym);});
        auto dis0 = hypot(f[0][0] - f[1][0], f[0][1] - f[1][1]);
        auto dis1 = hypot(f[0][0] - f[2][0], f[0][1] - f[2][1]);
        for(int i = 1; i < 3; i++){
            if(dis0 != hypot(f[i][0] - f[i + 1][0], f[i][1] - f[i+1][1])) return false;
        }
        if(abs(dis1 - sqrt(2) * dis0) > 1e-6) return false;
        return true;
    }
};
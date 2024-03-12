// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    using pii = pair<int, int>;
    pii sim(pii f){
        if(f.second < 0) f.first *= -1, f.second *= -1;
        int g = gcd(f.first, f.second);
        return {f.first / g, f.second / g};
    }
    int maxPoints(vector<vector<int>>& points) {
        if(points.size() < 3 ) return points.size();
        map<pair<pii, pii>, int>m;
        int ans = -1;
        for(int i = 0; i < points.size() - 1; i++){
            for(int j = i + 1; j < points.size(); j++){
                int x0 = points[i][0], y0 = points[i][1];
                int x1 = points[j][0], y1 = points[j][1];
                pii a, b;
                if(x0 - x1){
                    a = sim({y1 - y0, x1 - x0});
                    b = sim({y1 * (x1 - x0) - x1 * (y1 - y0), (x1 - x0)});
                }else{
                    a = {1e9, 0}, b = {x0, 0}; 
                }
                m[{a, b}]++;
                ans = max(ans, m[{a, b}]);
            }
        }
        for(auto &[key, val]: m){
            auto a = key.first, b = key.second;
            cout << a.first << ' ' << a.second << ' ' << b.first << ' ' << b.second << ' ' << val << endl;
        }
        cout << ans << endl;
        return ceil(sqrt(ans * 2));
    }
};
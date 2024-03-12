// https://leetcode.com/problems/max-points-on-a-line

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        using pii = pair<double, double>;
        map<pii, int>m;
        int ans = -1;
        for(int i = 0; i < points.size() - 1; i++){
            for(int j = i + 1; j < points.size(); j++){
                double x0 = points[i][0], y0 = points[i][1];
                double x1 = points[j][0], y1 = points[j][1];
                double a, b;
                cout << x0 << ' ' << y0 << ' ' << x1 << ' ' << y1 << endl;;
                if(x0 - x1){
                    a = (y1-y0) / (x1-x0);
                    b = y1 - a * x1;
                }else{
                    a = 1e9, b = 0; 
                }
                cout << a << ' ' << b << endl;
                m[{a, b}]++;
                ans = max(ans, m[{a, b}]);
            }
        }
        return ceil(sqrt(ans * 2));
    }
};
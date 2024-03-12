// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles

class Solution {
public:
    using ll = long long;
    using pii = pair<int, int>;
    using vi = vector<int>;
    
    long long common(vi bL0, vi tR0, vi bL1, vi tR1){
        if(bL0[0] > tR1[0] || bL1[0] > tR0[0] || bL0[1] > tR1[1] || bL1[1] > tR0[1]) return 0;
        ll ans = 0;
        vector<int> x = {bL0[0], tR0[0], bL1[0], tR1[0]};
        vector<int> y = {bL0[1], tR0[1], bL1[1], tR1[1]};
        sort(x.begin(), x.end());
        sort(y.begin(), y.end());
        ans = min(x[2] - x[1], y[2] - y[1]);
        return ans;
    }
    
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        
        ll ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                ll c = common(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]);
                ans = max(ans, c*c);
            }
        }
        return ans;
    }
};
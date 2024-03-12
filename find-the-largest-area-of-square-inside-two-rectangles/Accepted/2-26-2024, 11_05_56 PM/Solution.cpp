// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles

class Solution {
public:
    using ll = long long;
    using pii = pair<int, int>;
    using vi = vector<int>;
    
    int* merge(int* l, int* r){
        int* ans = new int[4];
        int lc = 0, rc = 0, ansc = 0;
        
        while (lc < 2 && rc < 2) {
            if (l[lc] < r[rc]) {
                ans[ansc++] = l[lc++];
            }else{
                ans[ansc++] = r[rc++];
            }
        }
        while (lc < 2) {
            ans[ansc++] = l[lc++];
        }
        while (rc < 2) {
            ans[ansc++] = r[rc++];
        }
        return ans;
    }

    int common(vi& bL0, vi& tR0, vi& bL1, vi& tR1){
        if(bL0[0] > tR1[0] || bL1[0] > tR0[0] || bL0[1] > tR1[1] || bL1[1] > tR0[1]) return 0;
        int ans = 0;
        int lx[2] = {bL0[0], tR0[0]}, rx[2] = {bL1[0], tR1[0]};
        int ly[2] = {bL0[1], tR0[1]}, ry[2] = {bL1[1], tR1[1]};
        int *x = merge(lx, rx);
        int *y = merge(ly, ry);
        ans = min(x[2] - x[1], y[2] - y[1]);
        return ans;
    }

    
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        
        int ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                int c = common(bottomLeft[i], topRight[i], bottomLeft[j], topRight[j]);
                ans = max(ans, c);
            }
        }
        return ll(ans) * ll(ans);
    }
};
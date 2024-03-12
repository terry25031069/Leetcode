// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles

class Solution {
public:
    using ll = long long;
    using pii = pair<int, int>;
    using vi = vector<int>;
    
    int common(vi bL0, vi tR0, vi bL1, vi tR1){
        if(bL0[0] > tR1[0] || bL1[0] > tR0[0]) return -1;
        if(bL0[1] > tR1[1] || bL1[1] > tR0[1]) return -2;
        int ans = 0;
        int x[4] = {bL0[0], tR0[0], bL1[0], tR1[0]};
        int y[4] = {bL0[1], tR0[1], bL1[1], tR1[1]};
        sort(x, x + 4);
        sort(y, y + 4);
        ans = min(x[2] - x[1], y[2] - y[1]);
        return ans;
    }
    
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        vector<vector<int>> rect;
        for(int i = 0; i < n; i++){
            rect.push_back({bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]});
        }
        sort(rect.begin(), rect.end());
        
        int ans = 0;
        int i = 0, j = 1;
        while(j < n){
            int c = common({rect[i][0], rect[i][1]}, {rect[i][2], rect[i][3]}, {rect[j][0], rect[j][1]}, {rect[j][2], rect[j][3]});
            if(ans > -1)ans = max(ans, c), j++;
            else{
                if(ans == -1) i++;
            }
        }
        return ll(ans) * ll(ans);
    }
};
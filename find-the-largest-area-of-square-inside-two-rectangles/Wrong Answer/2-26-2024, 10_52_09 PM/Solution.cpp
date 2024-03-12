// https://leetcode.com/problems/find-the-largest-area-of-square-inside-two-rectangles

class Solution {
public:
    using ll = long long;
    using pii = pair<int, int>;
    using vi = vector<int>;
    
    long long common(vi& bL0, vi& tR0, vi& bL1, vi& tR1){
        if(bL0[0] > tR1[0] || bL1[0] > tR0[0] || bL0[1] > tR1[1] || bL1[1] > tR0[1]) return 0;
        cout << "yee\n";
        ll ans = 0;
        int x, y;
        if(tR0[0] <= tR1[0]) x = tR0[0] - bL1[0];
        else x = tR1[0] - tR0[0];
        if(tR0[1] <= tR1[1]) y = tR0[1] - bL1[1];
        else y = tR1[1] - tR0[1];
        ans = min(x, y);
        return ans;
    }
    
    long long largestSquareArea(vector<vector<int>>& bottomLeft, vector<vector<int>>& topRight) {
        int n = bottomLeft.size();
        vector<vector<int>> rect;
        for(int i = 0; i < n; i++){
            rect.push_back({bottomLeft[i][0], bottomLeft[i][1], topRight[i][0], topRight[i][1]});
        }
        sort(rect.begin(), rect.end(), 
            [](vector<int> a, vector<int> b){
                return a < b;
            }
        );
        
        ll ans = 0;
        for(int i = 0; i < n - 1; i++){
            for(int j = i + 1; j < n; j++){
                vector<int> bL0{rect[i][0], rect[i][1]}, bL1{rect[j][0], rect[j][1]};
                vector<int> tR0{rect[i][2], rect[i][3]}, tR1{rect[j][2], rect[j][3]};
                ll c = common(bL0, tR0, bL1, tR1);
                ans = max(ans, c*c);
            }
        }
        return ans;
    }
};
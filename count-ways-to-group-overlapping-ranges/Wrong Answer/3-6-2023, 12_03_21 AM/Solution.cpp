// https://leetcode.com/problems/count-ways-to-group-overlapping-ranges

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int n = 1e9+7;
        sort(ranges.begin(), ranges.end());
        ranges.push_back({n, n});
        int g = 0;
        for(int i = 0, l = ranges[0][0], r = ranges[0][1]; i < ranges.size() - 1; i++){
            if(ranges[i+1][0] <= ranges[i][1]) r = ranges[i+1][1];
            else{
                g++;
                l = ranges[i][1], r = ranges[i][2];
            }
        }
        int ans = 1, bas = 2;
        while(g){
            if(g & 1) ans *= bas, ans %= n;
            g >>= 1, bas = bas * bas % n;
        }
        return ans;
    }
};
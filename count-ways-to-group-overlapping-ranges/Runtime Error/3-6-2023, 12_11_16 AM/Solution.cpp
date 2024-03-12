// https://leetcode.com/problems/count-ways-to-group-overlapping-ranges

class Solution {
public:
    int countWays(vector<vector<int>>& ranges) {
        int n = 1e9+7;
        sort(ranges.begin(), ranges.end());
        ranges.push_back({n, n});
        // for(auto v: ranges){
        //     for(auto ele: v) cout << ele << ' '; cout << endl;
        // }
        int g = 0;
        for(int i = 0, l = ranges[0][0], r = ranges[0][1]; i < ranges.size(); i++){
            if(ranges[i][0] <= r && ranges[i][1] > r) r = ranges[i][1];
            else{
                if(ranges[i][0] > r){
                    g++;
                    l = ranges[i][0], r = ranges[i][1];
                }
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
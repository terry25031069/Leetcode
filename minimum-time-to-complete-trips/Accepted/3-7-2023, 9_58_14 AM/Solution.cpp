// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
public:
    long long chk(unordered_map<int, int>& ma, long long m, long long tot){
        long long tmp = 0;
        for(auto [k, v]: ma) tmp += m / k * v;
        return tmp;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        unordered_map<int, int> ma;
        for(auto i: time) ma[i]++;
        long long ans, l, r, m;
        l = 1, r = int64_t(totalTrips) * (ma.begin()->first) + 1;
        while(l <= r){
            m = (l + r) / 2;
            long long tmp = chk(ma, m, totalTrips);
            if(tmp >= totalTrips){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};
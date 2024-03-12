// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
public:
    bool chk(unordered_map<int, int>& ma, long long m, long long tot){
        long long tmp = 0;
        for(auto [k, v]: ma){
            tmp += m / k * v;
            if(tmp >= tot) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        unordered_map<int, int> ma;
        for(auto i: time) ma[i]++;
        long long ans, l, r, m;
        l = 1, r = int64_t(totalTrips) * (ma.begin()->first) + 1;
        while(l <= r){
            m = (l + r) / 2;
            if(chk(ma, m, totalTrips)){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/minimum-time-to-complete-trips

#pragma GCC optimize("Ofast","inline","-ffast-math")
#pragma GCC target("avx,mmx,sse2,sse3,sse4")
class Solution {
public:
    bool chk(vector<int>& time, long long m, long long tot){
        long long tmp = 0;
        for(auto i: time){
            tmp += m / i;
            if(tmp >= tot) return true;
        }
        return false;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans, l, r, m;
        l = 1, r = int64_t(totalTrips) * (*min_element(time.begin(), time.end())) + 1;
        while(l <= r){
            m = (l + r) >> 1;
            if(chk(time, m, totalTrips)){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};
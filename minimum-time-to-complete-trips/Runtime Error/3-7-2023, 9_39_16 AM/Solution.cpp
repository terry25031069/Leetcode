// https://leetcode.com/problems/minimum-time-to-complete-trips

class Solution {
public:
    bool chk(vector<int>& time, long long m, long long tot){
        long long tmp = 0;
        for(auto i: time) tmp += m / i;
        return tmp >= tot;
    }
    long long minimumTime(vector<int>& time, int totalTrips) {
        long long ans, l, r, m;
        l = 1, r = 1e15;
        while(l <= r){
            m = (l + r) / 2;
            int tmp = chk(time, m, totalTrips);
            if(tmp){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};
// https://leetcode.com/problems/minimum-time-to-repair-cars

class Solution {
public:
    bool chk(vector<int>&ranks, int cars, long long m){
        long long tmp = 0;
        for(auto k: ranks) tmp += int(sqrt(m / k));
        return tmp >= cars;
    }
    long long repairCars(vector<int>& ranks, int cars) {
        long long l = 1, r = 1e18, m, ans;
        while(l <= r){
            m = l + (r - l) / 2;
            if(chk(ranks, cars, m)){
                ans = m;
                r = m - 1;
            }else l = m + 1;
        }
        return ans;
    }
};
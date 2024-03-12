// https://leetcode.com/problems/maximum-candies-allocated-to-k-children

class Solution {
public:
    bool chk(vector<int>& candies, int m, long long k){
        long long tmp = 0;
        for(auto i: candies){
            tmp += i / m;
            if(tmp >= k) return true;
        }
        return false;
    }
    int maximumCandies(vector<int>& candies, long long k) {
        int tot = 0, ma = -1;
        for(auto i: candies) tot += i, ma = max(ma, i); 
        if(tot < k) return 0;
        int l = 1, r = ma, m, ans;
        while(l <= r){
            m = (l + r) / 2;
            if(chk(candies, m, k)){
                ans = m;
                l = m + 1;
            }else r = m - 1;
        }
        return ans;
    }
};
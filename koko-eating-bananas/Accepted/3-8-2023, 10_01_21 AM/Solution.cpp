// https://leetcode.com/problems/koko-eating-bananas

class Solution {
public:
    bool chk(vector<int>& piles, int m, int h){
        int toth = 0;
        for(auto i: piles){
            toth += (i + m - 1) / m;
            if(toth > h) return false;
        }
        return toth <= h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1, r = 1e9, m, ans;
        while(l <= r){
            int m = (l + r) / 2;
            bool t = chk(piles, m, h);
            if(t){
                ans = m;
                r = m - 1;
            }else{
                l = m + 1;
            }
        }
        return ans;
    }
};
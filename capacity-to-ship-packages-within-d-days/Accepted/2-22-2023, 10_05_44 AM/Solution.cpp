// https://leetcode.com/problems/capacity-to-ship-packages-within-d-days

class Solution {
public:
    bool ver(int m, vector<int>& weights, int days){
        int idx = 0, capa;
        for(int i = 0; i < days; i++){
            capa = m;
            while(idx < weights.size() && capa >= weights[idx]){
                capa -= weights[idx++];
            }
        }
        return idx == weights.size();
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int l = 1, r = 1e8, m, ans;
        while(l <= r){
            m = (r - l) / 2 + l;
            if(ver(m, weights, days)){
                r = m - 1;
                ans = m;
            }else l = m + 1;
        }
        return ans;
    }
};